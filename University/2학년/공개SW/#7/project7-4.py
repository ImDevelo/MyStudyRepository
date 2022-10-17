def calsum(n) :
    if (n < 0) :
        raise ValueError
    sum = 0
    for a in range(n+1) :
        sum += a
    return sum
try :
    print(calsum(10))
    print(calsum(-5))
except :
    print("입력값이 잘못됨")