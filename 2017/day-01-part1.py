import sys

data = sys.stdin.readline().rstrip()
data += data[0]

s = 0

for i in range(len(data)-1):
  if data[i] == data[i+1]:
      s += int(data[i])

print(s)

