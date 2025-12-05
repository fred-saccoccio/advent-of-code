import sys

banks = []

for line in sys.stdin:
    banks.append(line.rstrip())

MAX_FOR_JOLTAGE = 12

total_joltage = 0

for bank in banks:
  
  missing_digits = 12  
  current_index = 0
  current_max_digit = -1
  joltage = 0
  start_index = 0
  next_index = 0
  
  while missing_digits != 0:
    for i in range(current_index, len(bank) - missing_digits + 1):
      if int(bank[i]) > current_max_digit:
        current_max_digit = int(bank[i])
        next_index = i + 1
      current_index = current_index + 1 
    joltage = joltage + current_max_digit*10**(missing_digits - 1)
    missing_digits = missing_digits - 1
    current_index = next_index
    current_max_digit = -1

  # print(joltage)
  total_joltage = total_joltage + joltage

print(f"joltage={total_joltage}")

