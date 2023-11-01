def fun1(x):
    if x == 1:
        return 1
    return fun1(x - (x + 2) // 3) + 1
def fun2(x):
    if x % 3 == 1:
        return 1
    return fun2(x - (x + 2) // 3) + 1
a = eval(input())
print(fun1(a), fun2(a))