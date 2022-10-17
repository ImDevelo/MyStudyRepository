class Human :
    def __init__(self, age, name) :
        self.age = age
        self.name = name
    def __le__(self, other) : #__eq__ 연산자 메소드를 이용해 <=으로 객체를 비교할시 실행
        return self.age <= other.age #이름이 같은지 출력
kim = Human(29,"홍길동") 
sang = Human(29,"홍길동")
moon = Human(30,"이순신")
print(kim<=sang) #연산자 메소드를 이용해 비교하고 있다. 나이가 같아 ture
print(kim<=moon) #나이가 더 적어 true