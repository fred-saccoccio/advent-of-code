import sys

verbose = False

def is_aba(s):
    return s[0] == s[2]

def supports_SSL(ip):
    in_square_brackets = False
    buff = ""
    aba = set()
    bab = set()
    index = 0
    try:
        for c in ip:
            if c == '[':
                in_square_brackets = True
                buff = ""
            elif c == ']':
                in_square_brackets = False 
                buff = ""
            else:
                buff = (buff + c)[-3:]
                # Check if aba
                if len(buff) == 3:
                    if is_aba(buff):
                        if in_square_brackets == False:
                            aba.add(buff)
                            if buff in bab:
                                raise Exception('buff in bab')
                        else:
                            r = "".join([buff[1],buff[0],buff[1]])
                            if r in aba:
                                raise Exception('r in aba')
                            else:
                                bab.add(r)
            index += 1
    except:
        return True 

    return False 

count = 0

while True:
    line = sys.stdin.readline().rstrip()

    if not line or (len(line) == 0):
        break

    if supports_SSL(line):
        if verbose == True:
            print(f"'{line}' -> SSL")
        count += 1

print(count)

