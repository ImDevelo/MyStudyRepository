from linecache import clearcache
import time
t = time.time() # 1970년 이후 지나온 시간을 초로 출력
                # 소수점은 나노 초(nano second) 까지
print(t)
print(time.ctime(t))        # 년도, 월, 일, 요일, 시간으로 변환 출력
print(time.localtime(t))    # struct_time 형식으로 변환 출력
start = time.time()
for a in range(100) :
    print(a, end=',')
print()
end = time.time()
print(end - start)