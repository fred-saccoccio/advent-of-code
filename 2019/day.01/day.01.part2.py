import sys
import math

def fuel_requirements(m):
    ret_val = []
    fuel = m
    while True:
        fuel = int(math.floor(fuel/3)) - 2
        if fuel <= 0:
            break
        ret_val.append(fuel) 
    return sum(ret_val)

total_fuel = 0
while True:
    line = sys.stdin.readline().rstrip()
    if not line or (len(line) == 0):
        break
    mass = int(line)
    fuel = fuel_requirements(mass)
    total_fuel += fuel

print(total_fuel)
