import hashlib
import sys

if len(sys.argv) < 2:
    print("Please specify the puzzle input on the command line.")
    exit(1)

# String to hash
text = sys.argv[1] # "yzbqklnj" is the input for this Advent Of Code challenge.

pwd = []
index = 0

while len(pwd) < 8:

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
            print(f"Intermediate md5:{hash_hex}")
            pwd.append(hash_hex[5])
            break


print(f'The answer is {"".join(pwd)}')

