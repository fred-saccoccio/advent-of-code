import re
import sys

def get_input_data_stream(argv):
    ret_val = None
    if len(argv) >= 2:
        ret_val = open(argv[1], "r")
    else:
        print("Please enter the data on stdin and end with CTRL+D")
        ret_val = sys.stdin

    return ret_val

txt = get_input_data_stream(sys.argv).read()
matches = re.findall("mul\(([0-9]{1,3}),([0-9]{1,3})\)|(do\(\))|(don't\(\))", txt)

p_tot_part1 = 0 
p_tot_part2 = 0 
enabled = True

for m in matches:
    if m[2] == 'do()':
        enabled = True
    elif m[3] == "don't()":
        enabled = False
    else:
        p = int(m[0]) * int(m[1])
        p_tot_part1 = p_tot_part1 + p
        if enabled:
            p_tot_part2 = p_tot_part2 + p

print(f"result for part 1={p_tot_part1}")
print(f"result for part 2={p_tot_part2}")

