a,t=input().split(':'),':'
for i in a:
    while i!='0' and i[0]=='0':
        i=i[1:]
    t+=i+':'
for i in range(8, 0, -1):
    tar=':0'*i+':'
    if t.find(tar)==-1:
        continue
    t=t.replace(tar,'::',1)
    break
if t=='::':
    print(t)
else:
    t=t[1:-1]
    if t[0]==':':
        t=':'+t
    if t[-1]==':':
        t=t+':'
    print(t)