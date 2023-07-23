n, k = map(int, input().split())
s = input()

a = []
f = []

for i in range(0, n + 1):
    a.append(0)
for i in range(0, n + 1):
    f.append(a[:])

for i in range(1, n + 1):
    f[i][0] = int(s[0 : i])

for p in range(1, k + 1):
    for i in range(p + 1, n + 1):
        for j in range(p, i):
            f[i][p] = max(f[i][p], f[j][p - 1] * int(s[j : i]))

print(f[n][k])
