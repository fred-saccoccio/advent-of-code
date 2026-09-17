import sys

def read_single_int():
    return int(sys.stdin.readline().rstrip())

def read_array_ints():
    return list(map(int, sys.stdin.readline().rstrip().split()))

PIN_PAD_MAX_INDEX = 4

def apply_move(p, move, arr):
    tmp = p[:]
    if move == "U":
        tmp[0] = max(0, tmp[0]-1)
    elif move == "D":
        tmp[0] = min(PIN_PAD_MAX_INDEX, tmp[0]+1)
    elif move == "L":
        tmp[1] = max(0, tmp[1]-1)
    elif move == "R":
        tmp[1] = min(PIN_PAD_MAX_INDEX, tmp[1]+1)

    if(arr[tmp[0]][tmp[1]] != '.'):
        p[0] = tmp[0]
        p[1] = tmp[1]

pinpad = [
    ['.','.','1','.','.'],
    ['.','2','3','4','.'],
    ['5','6','7','8','9'],
    ['.','A','B','C','.'],
    ['.','.','D','.','.']]
lines = []
current_pos = [2,0] # Points to the '5' key on the pinpad
code = []

while True:
    line = sys.stdin.readline()
    if not line:
        break
    line = line.rstrip()
    for m in line:
        apply_move(current_pos, m, pinpad)
    code.append(pinpad[current_pos[0]][current_pos[1]])

print("".join(code))

