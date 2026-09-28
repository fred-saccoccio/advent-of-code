import sys

verbose = False

def get_calibration(l):
    digits = []
    for c in l:
        if c.isdigit():
            if len(digits) == 0:
                digits.append(int(c))
                digits.append(int(c))
            else:
                digits[1] = int(c)
    if verbose:
        print(f"Found {digits} in '{line}'")
    
    return digits[0]*10+digits[1]

calibrations_sum = 0
while True:
    line = sys.stdin.readline()
    
    if not line:
        break
    line = line.rstrip()
    
    if len(line) == 0:
        break

    calibration = get_calibration(line)
    calibrations_sum += calibration

print(calibrations_sum)

