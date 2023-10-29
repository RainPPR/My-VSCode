a, b = input().split()
a = eval(a)
b = eval(b)
if a > b:
    if a - b > 3:
        print("No")
    else:
        print("Yes")
else:
    if b - a > 2:
        print("No")
    else:
        print("Yes")