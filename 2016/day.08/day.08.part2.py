import sys

LINES = 6 
COLUMNS = 50
screen = [['.' for i in range(COLUMNS)] for _ in range(LINES)]

def print_screen(s):
    for l in s:
        print("".join(l))

def process_op(op, scr):
    splits = op.split()
    inst = splits[0]
    if inst == "rect":
        # Get rect size
        s = splits[1].split("x")
        cols = int(s[0])
        lines = int(s[1])
        for l in range(lines):
            for c in range(cols):
                scr[l][c] = '#'
    elif inst == "rotate":
        rot_type = splits[1]
        index = int(splits[2].split("=")[1])
        pixels = int(splits[4])
        if rot_type == 'column':
            backup = [scr[l][index] for l in range(LINES)]
            for l in range(LINES):
                scr[l][index] = backup[(l-pixels)%LINES]
        else:
            pass
            backup = [scr[index][c] for c in range(COLUMNS)]
            for c in range(COLUMNS):
                scr[index][c] = backup[(c-pixels)%COLUMNS]

count = 0

while True:
    line = sys.stdin.readline().rstrip()

    if not line or (len(line) == 0):
        break

    process_op(line, screen)


for l in range(LINES):
    for c in range(COLUMNS):
        if screen[l][c] == '#':
            count += 1

print(count)
print_screen(screen)

