import sys

if len(sys.argv) >= 2:
    sys.stdin = open(sys.argv[1], "r")

# Store the entries
entries = []
while True:
    line = sys.stdin.readline().rstrip()
    if not line or (len(line) == 0):
        break
    entries.append(int(line))

# Process the entries
deltas = set()
answer = 0
for i in range(len(entries)-2):
    for j in range(i+1, len(entries)-1):
        for k in range(j+1, len(entries)):
            if entries[i]+entries[j]+entries[k] == 2020:
                indexes = i, j, k
                answer = entries[i] * entries[j] * entries[k]
                break

print(f"Sum = {answer}")
