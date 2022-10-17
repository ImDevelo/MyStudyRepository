import random
for i in range(5) :
    print(random.random()) # 난수 생성
for i in range(5) :
    print(random.randint(1, 10)) # 1 ~ 10 중의 정수 난수를 생성
for i in range(5) :
    print(random.uniform(1, 10)) # 1 ~ 10 중의 실수 난수를 생성
food = ["짜장면", "짬뽕", "탕수육", "군만두"]
print(random.choice(food)) # food 리스트에서 하나를 무작위 선택
print(random.sample(food, 2)) # food 리스트에서 2개를 선택
random.shuffle(food) # food 리스트의 요소를 무작위 섞음
print(food)