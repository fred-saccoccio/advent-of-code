import sys

if len(sys.argv) >= 2:
    sys.stdin = open(sys.argv[1], "r")

drifts = []
while True:
    line = sys.stdin.readline().rstrip()
    if not line or (len(line) == 0):
        break

    drift = int(line)
    drifts.append(drift)

frequency = 0
frequencies = set()
frequencies.add(frequency)
index = 0
while True:
    frequency += drifts[index]
    if frequency in frequencies:
        break
    else:
        frequencies.add(frequency)
    index = (index+1)%len(drifts)

print(frequency)
