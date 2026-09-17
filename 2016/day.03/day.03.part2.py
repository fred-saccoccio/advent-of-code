import sys

def read_single_int():
    return int(sys.stdin.readline().rstrip())

def read_array_ints():
    return list(map(int, sys.stdin.readline().rstrip().split()))

def is_triangle(t):
    if (t[0] < t[1]+t[2]) and (t[1] < t[0]+t[2]) and (t[2] < t[0]+t[1]):
        return True
    return False

count = 0
data = []
while True:
    line = sys.stdin.readline().rstrip()

    if not line or (len(line) == 0):
        break
    
    sides = list(map(lambda x: int(x), line.split()))
    data.append(sides)
   
index = 0
while index < len(data):
    for col in range(3):
        t = [data[index][col],data[index+1][col],data[index+2][col]]
        if is_triangle(t):
             count += 1
    index += 3

print(count)

