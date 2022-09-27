def sum(x) :    # x는 형식 매개변수
    x[0] = x[0] + 10
    
a = [5]         # a는 리스트로 가변 객체
sum(a)          # a는 실 매개변수
print(a[0])
