import sys
import re

def manhattan(c):
  return abs(c.real) + abs(c.imag)

def pretty_print(c,prefix=''):
    print(f"{prefix}({int(c.real)},{int(c.imag)})")

line = sys.stdin.readline().rstrip()

instructions = re.split(' |, ', line) # line.split(", ")

verbose = False

# We use complex numbers to store the coordinates of the grid.
# Rotation right => * (-1j)
# Rotation left  => * 1j
current_position = 0j
# heading : 
#   0 + 1j: North
#   1 + 0j : East
#   0 - 1j : South
#  -1 + 0j : West
heading = 1j # Initialze to NORTH

visited = set()
visited.add(current_position)

target_hit = False

for instruction in instructions:
  if target_hit:
      break;
  if verbose:
    print(f">>> Processing {instruction}")
    pretty_print(current_position,"start>")
  direction = instruction[0]

  if direction == 'R':
    rotation = -1j 

  if direction == 'L':
    rotation = 1j
  
  steps = int(instruction[1:])

  heading *= rotation

  for i in range(steps):
      current_position += heading
      if current_position in visited:
          target_hit = True
          break;
      visited.add(current_position)

      if verbose:
        pretty_print(current_position)

print(current_position)
print(int(manhattan(current_position)))

