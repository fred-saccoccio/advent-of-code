import sys

verbose = False

def parse(s):
    splits = s.split(":")
    pwd = splits[1].strip()
    splits = splits[0].split()
    letter = splits[1]
    splits = splits[0].split("-")
    min_occur = int(splits[0])
    max_occur = int(splits[1])
    return min_occur, max_occur, letter, pwd

valid_pwds = 0
while True:
    line = sys.stdin.readline()
    if not line:
        break
    line = line.rstrip() 
    m, M, l, p = parse(line)
    
    if verbose:
        print(f"{line} -> ", m, M, l)
    
    if (p[m-1] == l and p[M-1] != l) or (p[m-1] != l and p[M-1] == l):
        valid_pwds += 1

    if verbose:
        print(s)

print(valid_pwds)

