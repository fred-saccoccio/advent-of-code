import sys

def parse_inst(s):
   splits = s.split()
   return splits[0], int(splits[1])

position = 0
depth = 0
while True:
    line = sys.stdin.readline()
    if not line:
        break
    line = line.rstrip()
    direction, units = parse_inst(line)
    match direction:
        case 'forward':
            position += units
        case 'down':
            depth += units
            pass
        case 'up':
            depth -= units
            pass
        case _:
            pass

print(f"position={position}, depth={depth}")
print(position*depth)

