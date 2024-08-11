def spam(eggs) :
    eggs.append(100)
    eggs = [2, 3]
    eggs.append(1)
    print(eggs)
ham = [0]
spam(ham)
print(ham)