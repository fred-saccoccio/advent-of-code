import sys

OPCODE_ADD = 1
OPCODE_MULT = 2
OPCODE_HALT = 99


class IntcodeMachine():
    def __init__(self):
        self.ip = 0
        self.program = []

    def get_value(self, idx):
        return self.program[idx]
    
    def set_value(self, idx, v):
        self.program[idx] = v

    def compile(self, s):
        self.program = list(map(int, s.split(",")))
        
    
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

intC.set_value(1,12)
intC.set_value(2,2)

intC.run()

print(intC.get_value(0))

