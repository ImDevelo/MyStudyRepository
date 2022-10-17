class Calounter:
    count = 0 #클래스 맴버
    def __init__(self):
        Calounter.count +=1
    
    def print_count(self):
        print(self.count)

a = Calounter()  
a.print_count() 
b = Calounter() 
b.print_count() 