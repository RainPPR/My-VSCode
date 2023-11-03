from math import sqrt
def isprime(x):
    if x <= 1:
        return False
    t=int(sqrt(x))+1
    for _ in range(2, t):
        if x%_==0:
            return False
    return True
n=int(input())
for _ in range(n):
    l,r=map(int,input().split())
    for __ in range(l,r+1):
        if isprime(__):
            print(__)
    print()