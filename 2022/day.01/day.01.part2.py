import sys

current_sum = 0
index = 0

sums = []

while True:
    line = sys.stdin.readline()
    if not line:
        break
    line = line.rstrip()
    if len(line) == 0:
        sums.append(current_sum)
        current_sum = 0
    elif not line:
        break
    else:
        current_sum += int(line)
    index += 1

sums.append(current_sum)

sums.sort(reverse=True)

print(sum(sums[0:3]))

