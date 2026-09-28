import sys

depths = []
while True:
    line = sys.stdin.readline().rstrip()
    if not line or (len(line) == 0):
        break
    depths.append(int(line))

increases = 0
current_sum = sum(depths[0:3])
for i in range(0,len(depths)-2):
    if sum(depths[i:i+3]) > current_sum:
        increases += 1
    current_sum = sum(depths[i:i+3])

print(increases)

