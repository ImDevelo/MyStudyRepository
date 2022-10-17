class MyClass :
    var = "안녕하세요!!" # 클래스 맴버
    def sayHello(self) :
        msg1 = "안녕"
        self.msg2 = "Hi"
        print(msg1)
        print(self.var) 
obj = MyClass() 
print(obj.var)  #객체를 통해 클래스 맴버 출력
obj.sayHello()  #객체의 메소드에서 클래스 맴버를 불러와 출력
print(MyClass.var) #클래스 이름으로 직접 접근