import sys
import re
import functools

def read_single_int():
    return int(sys.stdin.readline().rstrip())

def read_array_ints():
    return list(map(int, sys.stdin.readline().rstrip().split()))

def parse_room(r):
    splits = r.split("-")
    blob = splits[-1]
    s = re.split("\[|\]",blob)
    _letters = "".join(splits[:-1])
    _id = int(s[0])
    _checksum = s[1]
    return _letters,_id,_checksum

# Compare function
# returns 
#   a negative value for less-than,   => a < b  -> -1 
#   zero if the inputs are equal,     => a == b ->  0
#   a positive value for greater-than => a > b  -> +1
def compare(a,b):
    if a[1] < b[1]:
        return -1
    if a[1] > b[1]:
        return 1
    # Here a[1] == b[1] : compare on [0]
    if a[0] > b[0]:
        return -1
    if a[0] < b[0]:
        return 1
    return 0

def checksum(r):
    stats = {}
    for l in r:
        if l in stats.keys():
            stats[l] += 1
        else:
            stats[l] = 1
    stats = list(stats.items())
    stats.sort(key=functools.cmp_to_key(compare), reverse=True)
    c = "".join([s[0] for s in stats[:5]])
    return c

data = []
count = 0
while True:
    line = sys.stdin.readline().rstrip()

    if not line or (len(line) == 0):
        break
    data_letters, data_id, data_checksum = parse_room(line)
    real_checksum = checksum(data_letters)
    if real_checksum == data_checksum:
        count += data_id 
    pass

print(count)

