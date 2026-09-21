import hashlib
import sys

if len(sys.argv) < 2:
    print("Please specify the puzzle input on the command line.")
    exit(1)

# String to hash
text = sys.argv[1] # "yzbqklnj" is the input for this Advent Of Code challenge.

pwd = ['x' for i in range(8)]
index = 0

while 'x' in pwd :

    while True:
        # Encode the current string into bytes
        entry = f"{text}{index}"
        entry_bytes = entry.encode('utf-8')

        # Compute the md5 hash
        hash_md5 = hashlib.md5(entry_bytes)

        # Retrieve the md5 hash as a hex string
        hash_hex = hash_md5.hexdigest()

        index = index + 1
        
        if hash_hex.startswith("00000"):
            pos = hash_hex[5]
            c = hash_hex[6]
            n_pos = int(pos,16)
            if 0 <= n_pos and n_pos <= 7 and pwd[n_pos] == 'x':
               pwd[n_pos] = c
               print(f"Intermediate md5:{hash_hex}")
               break

print(f'The answer is {"".join(pwd)}')

