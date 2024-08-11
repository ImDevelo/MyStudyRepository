str = "89점"
try :
    score = int(str)
except ValueError :
    print("점수의 형식이 잘못됨")
except IndexError :
    print("첨자가 범위를 벗어남")
else :
    print(score)