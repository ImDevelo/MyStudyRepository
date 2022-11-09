class BaseA:
    def __init__(self) :
        print('BaseA.__init__()')

class B(BaseA): # BaseA 클래스 상속
    def __init__(self) :
        print('B.__init__()')
        super().__init__() # 부모 클래스 BaseA 생성자 호출

b = B()
