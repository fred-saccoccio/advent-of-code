
nb_lines = int(input())
ribbon = 0
for i in range(nb_lines): 
    n1, n2, n3 = map(lambda s: int(s.strip()), input().split('x'))
    data = [n1, n2, n3]
    data.sort()
    ribbon = ribbon + 2*(data[0] + data[1]) + data[0]*data[1]*data[2]
pass
print(ribbon)
