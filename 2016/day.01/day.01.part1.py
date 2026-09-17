import sys
import re

line = sys.stdin.readline().rstrip()

instructions = re.split(' |, ', line) # line.split(", ")

print(instructions)

X = 0
Y = 0
# heading : 
#  0 : North
#  1 : East
#  2 : South
#  3 : West
heading = 0

for instruction in instructions:
  direction = instruction[0]
  delta_heading = 0

  if direction == 'R':
    delta_heading = 1

  if direction == 'L':
    delta_heading = -1
  
  s_steps = int(instruction[1:])

  heading = ((heading+delta_heading)%4 + 4)%4

  # North
  if heading == 0:
    Y = Y + s_steps

  # East
  if heading == 1:
    X = X + s_steps
  
  # South
  if heading == 2:
    Y = Y - s_steps
  
  # West
  if heading == 3:
    X = X - s_steps

  pass

print(X,Y)
print(abs(X)+abs(Y))
