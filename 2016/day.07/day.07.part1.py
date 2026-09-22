import sys

def is_TLS(ip):
    in_square_brackets = False
    match_ABBA = False
    prev = ""
    try:
        for c in ip:
            if c == '[':
                in_square_brackets = True
                prev = ""
            elif c == ']':
                in_square_brackets = False 
                prev = ""
            else:
                prev = (prev + c)[-4:]
                if len(prev) == 4:
                    if prev[0] == prev[3] and prev[1] == prev[2] and prev[0] != prev[1]:
                        if in_square_brackets:
                            raise Exception('--')
                        else:
                            match_ABBA = True
    except:
        return False

    return match_ABBA

count = 0

while True:
    line = sys.stdin.readline().rstrip()

    if not line or (len(line) == 0):
        break

    if is_TLS(line):
        count += 1


print(count)

