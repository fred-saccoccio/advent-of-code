import sys

verbose = False

def string_difference(s1,s2):
    ind = []
    if len(s1) != len(s2):
        raise Exception("Not the same length to compare strings")
    count = 0
    for i in range(len(s1)):
        if s1[i] != s2[i]:
            count += 1
        else:
            ind.append(i)
    return count, ind

data = []
while True:
    line = sys.stdin.readline()
    if not line:
        break

    data.append(line.rstrip())

strings_match_indexes = 0,0
char_indexes = []
count = 0
string1 = ""
string2 = ""

try :
    for i in range(len(data) - 1):
        for j in range(i+1, len(data)):
            _count, _char_indexes = string_difference(data[i], data[j])
            if _count == 1:
                string1, string2 = data[i], data[j]
                strings_match_indexes = i,j
                char_indexes = _char_indexes
                raise Exception()
except:
    pass

print(string1, string2)
print(strings_match_indexes)
print(char_indexes)
common = ""
for i in char_indexes:
    common += string1[i]
print(common)

