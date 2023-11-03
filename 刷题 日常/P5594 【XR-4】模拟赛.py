n,m,k=map(int,input().split())
a,r=[],[0]*k
for i in range(n):
    a.append(list(map(int,input().split())))
for i in range(m):
    t=[0]*k
    for j in range(n):
        t[a[j][i]-1]=1
    for j in range(k):
        r[j]+=t[j]
for i in r:
    print(i,end=' ')