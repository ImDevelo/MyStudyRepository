# print : 출력합니다.
print("<print>")
print("hello!")
print(3+41)

# abs(x) : 숫자의 절대값을 반환합니다. 
# 인수로 정수, 부종소수점 숫자 인수가 복소수면 크기를 반환합니다.
print("<abs>")
print(abs(-2))
print(abs(-0.4))

# sorted(iterable , key = None , reverse = False) : 정렬 
# key 는 iterable 의 각 요소에서 비교 키를 추출하는 데 사용되는 인수 하나의 함수를 지정합니다 
print("<sorted>")
sample_list = [3,2,4,5,1]
print(sorted(sample_list))
print(sorted(sample_list, reverse=True))

# 두먼째 인자인 start는 디폴트 값은 0입니다.
print("<sum>")
print(sum([10],5))
print(sum([1,2,3,4,5]))
print(sum([1,2,3,4],5))

# max(iterable, [iterable]) 혹은 max(arg1, arg2,..) : 받은 매개변수를 중 가장 큰값을 반환
print("<max>")
sample_list = [1,2,3]
print(max(sample_list))
print(max(sample_list, [5,6,7]))

# min(iterable, [iterable]) 혹은 min(arg1, arg2,..) : 받은 매개변수를 중 가장 작은값을 반환
print("<min>")
sample_list = [1,2,3]
print(min(sample_list))
print(min(sample_list, [5,6,7]))


# type : 타입반환
print("<type>")
sample_list = []
sample_data = 3
print(type(sample_list))
print(type(sample_data))


# pow 제곱
print("<pow>")
print(pow(4,3))
print(pow(2,-1))

#len : 자료의 길이를 반환합니다.
print("<len>")
print(len("Hello"))
print(len([1,2,3,4,5]))

#reversed : 순서를 뒤집습니다.
print("<reversed>")
sample_list = [1,2,3,4,5]
print(list(reversed(sample_list)))
