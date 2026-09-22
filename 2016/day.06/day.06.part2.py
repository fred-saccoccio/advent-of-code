import sys
import functools

# Compare function for tuples <letter>,<occurences>
# in order to sort those tuples by occurences
# returns 
#   a negative value for less-than,   => a < b  -> -1 
#   zero if the inputs are equal,     => a == b ->  0
#   a positive value for greater-than => a > b  -> +1
def compare(a,b):
    if a[1] < b[1]:
        return -1
    if a[1] > b[1]:
        return 1
    return 0

stats = [] 

while True:
    line = sys.stdin.readline().rstrip()

    if not line or (len(line) == 0):
        break

    if len(stats) == 0:
        stats = [{} for _ in range(len(line))]
    col = 0
    for c in line:
        if c in stats[col].keys():
            stats[col][c] += 1
        else:
            stats[col][c] = 1

        col += 1

word = []
for s in stats:
    d = list(s.items())
    d.sort(key=functools.cmp_to_key(compare))
    word.append(d[0][0])
    
print("".join(word))
