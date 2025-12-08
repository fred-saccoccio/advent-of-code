import sys

index = 0

# If a file is specified on the cmd line, take it as input.
# Otherwise, take stdin as input
if len(sys.argv) >= 2:
    input_stream = open(sys.argv[1], "r")
else:
    input_stream = sys.stdin

ranges = []
for line in input_stream:
    line = line.rstrip()
    # An empty line means that this is the end of the data to process
    if len(line) == 0:
        break
    splits = line.split("-")
    ranges.append( (int(splits[0]), int(splits[1])) )

ranges.sort()

# print(ranges)

disjoint_union = []
l_bound, r_bound = ranges[0]

for r in ranges[1:]:

    # (l_bound, r_bound) and r are disjoint 
    if r_bound < r[0]:
        disjoint_union.append((l_bound, r_bound))
        l_bound,r_bound = r
    else:
        # Increase range to the right
        r_bound = max(r[1],r_bound)

disjoint_union.append((l_bound, r_bound))

#print(disjoint_union)

s = sum(r - l + 1 for l, r in disjoint_union)
print(s)
