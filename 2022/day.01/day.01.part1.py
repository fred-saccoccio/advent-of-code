import sys

current_sum = 0
max_sum = 0
index = 0
while True:
    line = sys.stdin.readline()
    if not line:
        break
    line = line.rstrip()
    if len(line) == 0:
        if current_sum > max_sum:
            max_sum = current_sum
        current_sum = 0
    elif not line:
        break
    else:
        current_sum += int(line)
    index += 1


if current_sum > max_sum:
    max_sum = current_sum

print(max_sum)

