ori=[]
s=input()
while s!="EOF":
    t=""
    for i in s:
        if i == '<':
            t=t[:-1]
        else:
            t+=i
    ori.append(t)
    s=input()
my=[]
s=input()
while s!="EOF":
    t=""
    for i in s:
        if i == '<':
            t=t[:-1]
        else:
            t+=i
    my.append(t)
    s=input()
time=int(input())
correct=0
for i,j in zip(ori,my):
    for a,b in zip(i,j):
        correct+=a==b
print(correct*60//time)