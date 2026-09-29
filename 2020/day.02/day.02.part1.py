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

def get_pwd_stats(p):
    stats = {}
    for i in range(0,26):
        stats[chr(ord('a')+i)] = 0
    for c in p:
        stats[c] += 1
    return stats

valid_pwds = 0
while True:
    line = sys.stdin.readline()
    if not line:
        break
    line = line.rstrip() 
    m, M, l, p = parse(line)
    
    if verbose:
        print(f"{line} -> ", m, M, l)
    
    s = get_pwd_stats(p)
    
    if s[l] >= m and s[l] <= M:
        valid_pwds += 1
    
    if verbose:
        print(s)

print(valid_pwds)

