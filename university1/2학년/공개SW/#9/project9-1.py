class Player :
    def __init__(self, name, height, weight) :
        self.number = 100
        self.name = name
        self.height = height
        self.weight = weight
    def print_info(self) : # 메소드는 매개변수 self를 가짐
        print(self.number)
        print(self.name)
        print(self.height)
        print(self.weight)
        

a = Player('gildong','178','75')
a.print_info()