import random

number_list = [x for x in range(1,31)]  # 1~30까지의 리스트
list_a = random.sample(number_list, 10) # number_list에서 1~30까지 데이터중 10개 추출 
list_b = random.sample(number_list, 10) # (한 리스트 안에 중복되는 데이터가 없게 하기 위함)

list_c = []
for i in list_b:
    isOverlap = False
    for j in list_a:
        if i==j:
            isOverlap = True
    if isOverlap:
        list_c.append(i) #list_a와 list_b의 교집합에 해당되는 데이터 list_c에 삽입


print(list_c)
