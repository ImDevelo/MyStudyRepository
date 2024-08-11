def same_number (num1, num2):
    same_list = []
    d1 = str(num1)
    d2 = str(num2)
    for index in d1:
        if d2.find(index) != -1:
            same_list.append(int(index))
    return same_list

#출력: 3 7
print(same_number(38472,173))

#출력: 5 9
print(same_number(135790,5892))
