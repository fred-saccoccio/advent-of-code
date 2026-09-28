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
for entry in entries:
    delta = 2020 - entry
    if entry in deltas:
        answer = entry * delta
        print(f"Found {entry} and {delta}")
        break
    else:
        deltas.add(delta)

print(f"Sum = {answer}")
