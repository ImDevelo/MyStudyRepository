a = [1, 2, 3]
b = [3, 4, 5]
for i in b:
    if i not in a:
        a.append(i)
        
print(a)