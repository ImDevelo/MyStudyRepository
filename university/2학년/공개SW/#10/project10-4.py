from struct import Struct


class Person:
    def greeeting(slef):
        print("안녕하세요")

class Student(Person):
    def greeeting(slef):
        super().greeeting()

kim = Student()
kim.greeeting()
