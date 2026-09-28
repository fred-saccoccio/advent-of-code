import sys

verbose = False 
digits = ['1', '2', '3', '4', '5', '6', '7', '8', '9']
digits_1st_letters = ['o', 't', 'f', 's', 'e', 'n']
digits_in_letters = [ "one", "two", "three", "four", "five", "six",  "seven", "eight", "nine"]
letters_to_int = { "one":1, "two":2, "three":3, "four":4, "five":5, "six":6, "seven":7, "eight":8, "nine":9}

def accept_digit(s,index):
    if s[index] in digits:
        return True, index+1, int(s[index])
    elif s[index] in digits_1st_letters:
        for d in digits_in_letters:
            if len(s)-index >= len(d):
                if s[index:index+len(d)] == d:
                    return True, index+1, letters_to_int[d] 
    
    return False, index+1, -1

def get_calibration(l):
    matched_digits = []
    index = 0
    
    while index < len(l):
        status, index, digit = accept_digit(l,index)
        if status:
            if len(matched_digits) == 0:
                matched_digits.append(digit)
                matched_digits.append(digit)
            else:
                matched_digits[1] = digit
    
    if verbose:
        print(f"Found {matched_digits} in '{line}'")
    
    return matched_digits[0]*10 + matched_digits[1]

calibrations_sum = 0
while True:
    line = sys.stdin.readline()
    
    if not line:
        break
    line = line.rstrip()

    if len(line) == 0:
        break

    calibration = get_calibration(line)
    if verbose:
        print(f"input='{line}' yields {calibration} calibration")
    calibrations_sum += calibration

print(calibrations_sum)

