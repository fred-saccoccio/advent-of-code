import sys
import re

def parse_room(r):
    splits = r.split("[")
    letters = splits[0]
    return splits[0]

def rotate(c,k):
    if c == "-":
        return ' '
    x = (ord(c) - ord('a') + k)%26
    return chr(x + ord('a'))

def decrypt(room):
    n = room.rfind("-")
    letters = room[:n]
    key = int(room[n+1:])
    d = list(map(lambda x: rotate(x,key), [x for x in letters]))
    return ("".join(d),key)

data = []
count = 0

while True:
    line = sys.stdin.readline().rstrip()
    if not line or (len(line) == 0):
        break
    crypted_room = parse_room(line)
    decrypted_room, k = decrypt(crypted_room)
    if re.match("north",decrypted_room):
        print(f"{decrypted_room}:{k}")
    pass

