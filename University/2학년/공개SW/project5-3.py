def func_multiple(x, y, z) :
    return z, y, x

a, b, c = func_multiple(1,2,3)
print(a, b, c)

d = func_multiple(1,2,3)
print(type(d))
print(d)