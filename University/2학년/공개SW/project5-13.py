def rotate(num_list):
    last_index = num_list.pop()
    num_list.insert(0,last_index)
    return num_list

#정답 4,1,2,3
print(rotate([1,2,3,4]))

#정답 1,4,3,2
print(rotate([4,3,2,1]))