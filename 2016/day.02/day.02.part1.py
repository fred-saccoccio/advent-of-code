import sys

def read_single_int():
    return int(sys.stdin.readline().rstrip())

def read_array_ints():
    return list(map(int, sys.stdin.readline().rstrip().split()))

def apply_move(p, move):
    if move == "U":
        p[0] = max(0, p[0]-1)
    elif move == "D":
        p[0] = min(2, p[0]+1)
    elif move == "L":
        p[1] = max(0, p[1]-1)
    elif move == "R":
        p[1] = min(2, p[1]+1)

pinpad = [
    ['1','2','3'],
    ['4','5','6'],
    ['7','8','9']]
lines = []
current_pos = [1,1]
code = []

while True:
    line = sys.stdin.readline()
    if not line:
        break
    line = line.rstrip()
    for m in line:
        apply_move(current_pos, m)
    code.append(pinpad[current_pos[0]][current_pos[1]])

print("".join(code))

