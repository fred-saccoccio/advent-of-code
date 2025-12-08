import sys
import math

# If a file is specified on the cmd line, take it as input.
# Otherwise, take stdin as input
if len(sys.argv) >= 2:
    input_stream = open(sys.argv[1], "r")
else:
    input_stream = sys.stdin

numbers = []
operators =  []

for line in input_stream:
    line = line.rstrip()
    
    splits = line.split()

    try:
        number = list(map(int, splits))
        numbers.append(number)
    except ValueError:
        # it's not an integer so it's the operators line
        operators = splits

index = 0
grand_total = 0

transposed = [[] for _ in range(len(numbers[0]))]

for number_line in numbers:
    index = 0
    for i in number_line:
        transposed[index].append(i)
        index = index+1

index = 0    
for line_number in transposed:
    if operators[index] == '+':
        grand_total = grand_total + sum(line_number)
    else:
        grand_total = grand_total + math.prod(line_number)
    index = index + 1

print(grand_total)