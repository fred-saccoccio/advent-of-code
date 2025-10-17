import hashlib
import sys

if len(sys.argv) < 2:
  exit(1)

# String to hash
text = sys.argv[1] # "yzbqklnj" is the input for this Advent Of Code challenge.
increment = 0

while True:
  # Encoder la chaîne en bytes
  entry = f"{text}{increment}"
  entry_bytes = entry.encode('utf-8')

  # Calculer le hash MD5
  hash_md5 = hashlib.md5(entry_bytes)

  # Obtenir le hash en hexadécimal
  hash_hex = hash_md5.hexdigest()

  if hash_hex.startswith("00000"):
    break

  increment = increment + 1

print(increment)