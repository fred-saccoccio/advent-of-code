import sys
import math 

def inverse_cantor(z):
    w = math.floor((math.sqrt(8 * z + 1) - 1) / 2)
    t = (w * (w + 1)) // 2
    y = z - t
    x = w - y
    return x, y

OPCODE_ADD = 1
OPCODE_MULT = 2
OPCODE_HALT = 99


class IntcodeMachine():
    def __init__(self):
        self.ip = 0
        self.program = []
        self.backup = []

    def get_value(self, idx):
        return self.program[idx]
    
    def set_value(self, idx, v):
        self.program[idx] = v

    def compile(self, s):
        self.program = list(map(int, s.split(",")))
        self.backup = self.program[:]

    def restore(self):
        self.program = self.backup[:]
        
    def run(self):
        self.ip = 0
        while True:
            match self.program[self.ip]:
                case 1:
                    self.program[self.program[self.ip+3]] = self.program[self.program[self.ip+1]] + self.program[self.program[self.ip+2]]
                    self.ip += 4
                case 2:
                    self.program[self.program[self.ip+3]] = self.program[self.program[self.ip+1]] * self.program[self.program[self.ip+2]]
                    self.ip += 4
                case 99:
                    break
                case _:
                    pass



    def get_program(self):
        return self.program

intC = IntcodeMachine()
line = sys.stdin.readline().rstrip()
intC.compile(line)

index = 0
noun = 0
verb = 0
while True:
    noun, verb = inverse_cantor(index)
   
    intC.restore()
    intC.set_value(1, noun)
    intC.set_value(2, verb)
    intC.run()

    if intC.get_value(0) == 19690720:
        break
    index += 1

print(noun, verb)
print(100 * noun + verb)

