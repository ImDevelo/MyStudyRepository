class Human :
    def __init__(self, name, school, number) :
        self.name = name
        self.school = school
        self.number = number
    def __str__(self) :
        return "이름 %s / 학교 %s / 학번 %d"%(self.name, self.school, self.number)
        
kim = Human("킴길동","명지대",60102231)
print(kim) # 객체 kim을 print -> __str__ 메소드가 호출됨