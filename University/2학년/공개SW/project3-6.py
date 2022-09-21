data = []
for i in range(5):
    data.append(int(input()))
max = data[0]
min = data[0]

for index in data:
    if max < index:
        max = index
    if min > index:
        min = index
    
print("min: {0}  max: {1}".format(min,max))