import sys
from enum import IntEnum

input_file = open(sys.argv[1], "r")

ranges = []
ingredients = []

class Mode(IntEnum):
    READ_RANGE = 1
    READ_ID = 2

current_mode = Mode.READ_RANGE

def is_in_range(i,r):
    return (i >= r[0]) and (i <= r[1])
# Read input data
for line in input_file:
    line = line.rstrip()
    if line == "":
        current_mode = Mode.READ_ID
        continue

    if current_mode == Mode.READ_RANGE:
        splits = line.split("-")
        r = [int(splits[0]), int(splits[1])]
        ranges.append(r)
    
    if current_mode == Mode.READ_ID:
       ingredients.append(int(line)) 

fresh_ingredients = 0

for ingredient in ingredients:
    is_fresh = False
    for range in ranges:
        if is_in_range(ingredient, range):
            is_fresh = True
            fresh_ingredients = fresh_ingredients + 1
            break

print(fresh_ingredients)

