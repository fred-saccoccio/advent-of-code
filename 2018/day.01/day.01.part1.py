import sys

if len(sys.argv) >= 2:
    sys.stdin = open(sys.argv[1], "r")

frequency = 0

while True:
    line = sys.stdin.readline().rstrip()

    if not line or (len(line) == 0):
        break

    drift = int(line)
    frequency += drift

print(frequency)
