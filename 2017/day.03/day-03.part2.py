import numpy as np

EAST  =  0,1
NORTH = -1,0
WEST  =  0,-1
SOUTH =  1,0

directions = [EAST, NORTH, WEST, SOUTH]

def neighbours(arr, line, col):
    res = []

    for dl in (-1, 0, 1):
        for dc in (-1, 0, 1):
            if dl == dc == 0:
                continue

            l, c = line + dl, col + dc

            if 0 <= l < len(arr) and 0 <= c < len(arr[0]):
                res.append((l,c))

    return res

def sum_neighbours(arr, line, col):
    _neighbours = neighbours(arr, line, col)
    s = 0
    for n in _neighbours:
        s = s + arr[n[0]][n[1]]
    arr[line][col] = s
    return s

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
    if step >= target:
        raise StepReachedError(f"step {target} reached")  

square_size = 0
target = int(input().rstrip()) # 368078
step = 1
direction = 0
actual_steps = 0
N = 100
data_grid = [[0 for i in range(N)] for i in range(N)]
current_point = N//2,N//2
data_grid[N//2][N//2] = 1
current_val = 1

while current_val < target:
    try:
        # go EAST ->
        for i in range(square_size+1):
            current_point = add_tuple(current_point, directions[direction])
            current_val = sum_neighbours(data_grid,current_point[0], current_point[1])
            check_step(current_val,target)
        direction = (direction+1)%4 # => dir = NORTH
        # NORTH ^
        #       |
        for i in range(square_size+1):
            current_point = add_tuple(current_point, directions[direction])
            current_val = sum_neighbours(data_grid,current_point[0], current_point[1])
            check_step(current_val,target)
        square_size += 1
        direction = (direction+1)%4 # => dir = WEST 
        # WEST <- 
        for i in range(square_size+1):
            current_point = add_tuple(current_point, directions[direction])
            current_val = sum_neighbours(data_grid,current_point[0], current_point[1])
            check_step(current_val,target)
        direction = (direction+1)%4 # => dir = SOUTH 
        # SOUTH |
        #       v
        for i in range(square_size+1):
            current_point = add_tuple(current_point, directions[direction])
            current_val = sum_neighbours(data_grid,current_point[0], current_point[1])
            check_step(current_val,target)
        square_size += 1
        direction = (direction+1)%4 # => dir = WEST 
    except StepReachedError as e:
        break

print(current_point)
print(current_val)

