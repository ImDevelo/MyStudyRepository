class Person:
    def __init__(self, name , height, weight) :
        self.name = name
        self.helght = height
        self.weight = weight
    
    def print_info(self):
        if self.helght - 100 < self.weight:
            print("만")
        else:
            print("굿")

class Student(Person):
    def __init__(self, name, height, weight, phoneNumber, school):
        super().__init__(name, height, weight)
        self.phoneNumber = phoneNumber
        self.school = school


name = input()
height = input()
weight = input()

p = Person(name, height,weight)

p.print_info()