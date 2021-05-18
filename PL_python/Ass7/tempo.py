f = open("ga.txt", "r")
lines = 0
words = 0

x = f.read()
# print(x)
words = x.split()

# print(words)

f.seek(0)
while f.readline():
    lines += 1

print(f"No. of Lines = {lines}\nNo. of Words = {len(words)}")
