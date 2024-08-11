class Human :
    def __init__(self, age, name) :
        self.age = age
        self.name = name
    def intro(self) :
        print(str(self.age) + "살" + self.name + "입니다")
        
class Student(Human) :
    def __init__(self,age, name, s) :
        super().__init__(age, name)
        self.school = s

    def intro(self) :
        print(self.name + "의 학교는 " + self.school + "입니다")

kim = Human(29, "홍길동")
kim.intro()

kim2 = Student(25, "이순신","명지대")
kim2.intro()
