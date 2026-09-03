import sys

data = sys.stdin.readline().rstrip()

s = 0
fullway = len(data)
halfway = len(data) // 2

for i in range(len(data)):
  if data[i] == data[(i+halfway)%fullway]:
      s += int(data[i])

print(s)
 
