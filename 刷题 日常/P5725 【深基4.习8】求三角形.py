n=int(input())
for i in range(n):
    for j in range(n):
        s = str(i * n + j + 1)
        if len(s) == 1:
            s='0'+s
        print(s,end='')
    print()
print()
for i in range(n):
    for j in range(n - i - 1):
        print('  ',end='')
    for j in range(i + 1):
        s = str(i * (i + 1) // 2 + j + 1)
        if len(s) == 1:
            s='0'+s
        print(s,end='')
    print()