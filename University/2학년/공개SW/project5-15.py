def func(a, b) :
      "이것은 함수의 도움말입니다"    # 몸체 첫 문자열은 함수의 도움말로 정의됨
      b, a = a, b             # a b를 각각 b a에 대입
      return a, b             # a와 b 값 리턴

print(func)                   # 함수 주소 출력
print(type(func))             # func의 타입 출력 (function)
print(func.__doc__)           # __doc__ 은 함수에 정의된 도움말       

print(func(10,20))            # 함수func이 매게변수 10,20을 받아 두 숫자를 바꾼 20, 10을 출력한다.
c, d = func(1, 2)             # 함수func이 매게변수 10,20을 받아 두 숫자를 바꾼뒤 리턴 값 2, 1을 각각 c와 d에 대입한다.
print(c, d)                   # 결과값 c, d 출력: 2 1