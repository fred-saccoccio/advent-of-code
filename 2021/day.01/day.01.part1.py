import sys

depths = []
while True:
    line = sys.stdin.readline().rstrip()
    if not line or (len(line) == 0):
        break
    depths.append(int(line))

increases = 0
for i in range(0,len(depths)-1):
    if depths[i+1] > depths[i]:
        increases += 1

print(increases)

