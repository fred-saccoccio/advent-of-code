def couple_cantor(a,b):
  return ((a+b)*(a+b+1) // 2) + b

def f_inv(z):
  if z>= 0:
    return 2*z
  else:
    return -2*z - 1
  
def hhash(a,b):
  return couple_cantor(f_inv(a), f_inv(b))

current_x = 0
current_y = 0
visited = { 0 : [0,0] }

directions = input()
for c in directions:
  char_ok = False
  if c == '>':    # EAST
    char_ok = True
    current_x = current_x + 1
  elif c == '<':  # WEST
    current_x = current_x - 1
    char_ok = True
  elif c == "^":  # NORTH
    current_y = current_y + 1
    char_ok = True
  elif c == "v":  # SOUTH
    current_y = current_y - 1
    char_ok = True
  
  if char_ok:
    h = hhash(current_x, current_y)
    if h not in visited:
      visited[h] = [current_x, current_y]

print(len(visited))