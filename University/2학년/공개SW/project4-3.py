a = [1, 2, 3]
b = [3, 4, 5]
c = a
for i in b:
    isOverlap = False
    for j in a:
        if i==j:
            isOverlap = True
    if not isOverlap:
        c.append(i)

print( c )