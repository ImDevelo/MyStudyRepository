class TestPrivate :
    def __init__(self) :
        self.a = 100 # a는 public 멤버
        self.__b = 200 # b는 private 멤버
        self.__num = 300

    def print_member(self) :
        print(self.a)
        print(self.__b)
        print(self.__num)

obj = TestPrivate()
obj.print_member()

print(obj.a)
#print(obj.__b)