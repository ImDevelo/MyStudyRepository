class CalCounter :
    count = 0 # 클래스 멤버
    def __init__(self) :
        self.count += 1 # 객체의 count를 접근
    def print_count(self) :
        print(self.count)

a = CalCounter()
a.print_count()
b = CalCounter()
b.print_count()