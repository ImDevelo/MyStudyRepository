a, b = 12, 34
print(a, b)
a, b = b, a
print(a, b)
score = (88, 95, 70, 100, 99)
#score[0] = 100         # 튜플은 값의 변경이 불가함
L_score = list(score)   # list()는 리스트로 변환해줌
L_score[0] = 100
print(L_score)
