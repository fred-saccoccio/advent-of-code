import numpy as np

EAST  = 1,0
NORTH = 0,1
WEST  = -1,0
SOUTH = 0,-1

directions = [EAST, NORTH, WEST, SOUTH]

def manhattan_distance(a,b):
    return (max(a[0],b[0])-min(a[0],b[0])) + (max(a[1],b[1])-min(a[1],b[1]))

def add_tuple(t1,t2):
    return tuple(np.add(np.array(t1), np.array(t2)).tolist())

class StepReachedError(Exception):
    """Exception raised for custom error scenarios."""

    def __init__(self, message):
        self.message = message
        super().__init__(self.message)

def check_step(step,target):
    if step == target:
        raise StepReachedError(f"step {target} reached")  

#d = manhattan_distance((0,0),(2,1))
#print(d)

size = 0
current_point = 0,0
target = int(input().rstrip()) # 368078
step = 1
direction = 0
actual_steps = 0

while step < target:
    try:
        # go EAST ->
        for i in range(size+1):
            current_point = add_tuple(current_point, directions[direction])
            step += 1
            check_step(step,target)
        direction = (direction+1)%4 # => dir = NORTH
        # NORTH ^
        #       |
        for i in range(size+1):
            current_point = add_tuple(current_point, directions[direction])
            step += 1
            check_step(step,target)
        size += 1
        direction = (direction+1)%4 # => dir = WEST 
        # WEST <- 
        for i in range(size+1):
            current_point = add_tuple(current_point, directions[direction])
            step += 1
            check_step(step,target)
        direction = (direction+1)%4 # => dir = SOUTH 
        # SOUTH |
        #       v
        for i in range(size+1):
            current_point = add_tuple(current_point, directions[direction])
            step += 1
            check_step(step,target)
        size += 1
        direction = (direction+1)%4 # => dir = WEST 
    except StepReachedError as e:
        break

print(current_point)
print(manhattan_distance((0,0), current_point))

