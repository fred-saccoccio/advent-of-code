
nb_lines = int(input())
surface = 0
for i in range(nb_lines): 
    n1, n2, n3 = map(lambda s: int(s.strip()), input().split('x'))
    data = [n1, n2, n3]
    data.sort()
    surface = surface + 3*data[0]*data[1] + 2*data[1]*data[2] + 2*data[0]*data[2]
pass
print(surface)
