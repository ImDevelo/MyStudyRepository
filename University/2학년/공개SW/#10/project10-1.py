class Method_test :
    @staticmethod
    def static_method_1():
        print('static method 1')

    @staticmethod
    def static_method_2() :
        Method_test.static_method_1()

    @classmethod
    def class_method_1(cls) :
        cls.static_method_2()

Method_test.class_method_1()
Method_test.static_method_1()