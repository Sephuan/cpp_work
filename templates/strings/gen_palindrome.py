def gen_palindrome():
    base = 1
    while True:
        for i in range(base, base * 10):
            s = str(i)
            x = int(s + s[::-1][1:])
            yield x
        for i in range(base, base * 10):
            s = str(i)
            x = int(s + s[::-1])
            yield x
        base *= 10
MX = 2_000_000_002
palindrome = [[0], [0]]
for x in gen_palindrome():
    if x > MX:
        break
    palindrome[x % 2].append(x)

print(palindrome[0][::-1][:50][::-1])
print(palindrome[1][::-1][:50][::-1])