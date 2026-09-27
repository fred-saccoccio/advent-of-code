import sys
import math

total_fuel = 0
while True:
    line = sys.stdin.readline().rstrip()
    if not line or (len(line) == 0):
        break
    mass = int(line)
    fuel = int(math.floor(mass/3)) - 2
    total_fuel += fuel

print(total_fuel)
