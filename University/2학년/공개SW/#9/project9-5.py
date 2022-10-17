class MyClass :
    var = "안녕하세요!!" # 클래스 맴버
    def sayHello(self) :
        msg1 = "안녕"
        self.msg2 = "Hi"
        print(msg1)
        print(self.var)
        self.var = "Hello World" #함수내에서 새로운 var 정의
obj = MyClass() 
obj.sayHello()  #객체의 메소드에서 클래스 맴버를 불러와 출력
print(obj.var)  #객체를 통해 클래스 맴버 출력 - 앞선 결과에서 새롭게 정의한 var 출력
print(MyClass.var) #클래스 이름으로 직접 접근