t1 = int(input())
t2 = int(input())
t3 = int(input())
t4 = int(input())
t5 = int(input())

def intsum(*ints):
    sum = 0
    for s in ints:
        sum += s
    return sum


print(intsum(t1,t2,t3,t4,t5))

