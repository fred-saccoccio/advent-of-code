import sys

current_floor = 0
current_position = 1

while True:
    char = sys.stdin.read(1)  # Read a single char
    
    if char == '':  # EOF reached
        break
    
    if char == '(':    # Go UP one floor
        current_floor = current_floor +1 
    elif char == ')' : # Go DOWN one florr
        current_floor = current_floor - 1
    
    if current_floor == -1:
        break;
    current_position = current_position + 1

print(current_position)
