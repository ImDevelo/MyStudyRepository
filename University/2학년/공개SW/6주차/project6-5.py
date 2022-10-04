import random
import statistics

data=[]
for i in range(10): #1~100까지의 난수를 10개 뽑아 리스트에 저장
  number=random.random(1,100)
  data.append(number)

print(statistics.mean(data))  #평균
print(statistics.stdev(data)) #표준편차
