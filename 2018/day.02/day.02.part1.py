import sys

verbose = False

def compute_stats(s):
    stats = {}

    for c in s:
        if  c in stats.keys():
            stats[c] += 1
        else:
            stats[c] = 1

    return stats

def transpose_stats(s):
    t = {}
    for k,v in s.items():
        if v in t.keys():
            t[v] += 1
        else:
            t[v] = 1
    return t

twos = 0
threes = 0
while True:
    line = sys.stdin.readline()
    if not line:
        break

    line = line.rstrip()
    s = compute_stats(line)
    trans = transpose_stats(s)
    if 2 in trans.keys():
        twos += 1
    if 3 in trans.keys(): 
        threes += 1
    if verbose:
        print(line)
        print(s)
        print(trans)
        print(f"twos={twos}, threes={threes}")
        print()

print(twos*threes)

