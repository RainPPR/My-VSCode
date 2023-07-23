from math import *

n = int(input())
a = []

t = 0
for i in range(2, n):
    t += i
    a.append(i)
    
    if t - n == 1:
        a.remove(2)
        a[a.size() - 1] += 1
        break
    elif t - n > 1:
        a.remove(t - n)
        break

ans = 1
for i in a:
    ans *= i
    print(i, end= ' ')

print()
print(ans)
