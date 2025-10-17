def couple_cantor(a,b):
  return ((a+b)*(a+b+1) // 2) + b

def f_inv(z):
  if z>= 0:
    return 2*z
  else:
    return -2*z - 1
  
def hhash(a,b):
  return couple_cantor(f_inv(a), f_inv(b))

current_x_santa = 0
current_y_santa = 0
current_x_robot = 0
current_y_robot = 0
visited = { 0: { "coord": [0,0], "gifts": 2 } }

direction_index = 0
directions = input()
for c in directions:
  char_ok = False
  santa_is_working = (direction_index % 2) == 0
  if c == '>':    # EAST
    char_ok = True
    if santa_is_working:
      current_x_santa = current_x_santa + 1
    else:
      current_x_robot = current_x_robot + 1
  elif c == '<':  # WEST
    char_ok = True
    if santa_is_working:
      current_x_santa = current_x_santa - 1  
    else:
      current_x_robot = current_x_robot - 1  
  elif c == "^":  # NORTH
    char_ok = True
    if santa_is_working:
      current_y_santa = current_y_santa + 1
    else:
      current_y_robot = current_y_robot + 1
    
  elif c == "v":  # SOUTH
    char_ok = True
    if santa_is_working:
      current_y_santa = current_y_santa - 1
    else:
      current_y_robot = current_y_robot - 1
  
  if char_ok:
    if santa_is_working:
      current_x = current_x_santa
      current_y = current_y_santa
    else:
      current_x = current_x_robot
      current_y = current_y_robot
    
    h = hhash(current_x, current_y)
    
    if h not in visited:
      visited[h] = { "coord": [current_x, current_y], "gifts": 1 }
    else:
      visited[h]["gifts"] = visited[h]["gifts"] + 1
  
  direction_index = direction_index + 1

print(len(visited))