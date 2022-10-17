class Human :
    def __init__(self, age, name) :
        self.age = age
        self.name = name
    def __radd__(self, number) : #__eq__ 연산자 메소드를 이용해 <=으로 객체를 비교할시 실행
        return self.age + number # 1 + 이름 하여 리턴
kim = Human(29,"홍길동") 
sang = Human(29,"홍길동")
moon = Human(30,"이순신")
print(1 + kim) #현제 나이에 +1 = 30
print(2 + moon) #현제 나이에 +2 = 32