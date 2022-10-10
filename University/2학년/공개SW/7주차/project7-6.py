str = "89점"
try :
    score = int(str)
except ValueError as e :
    print(e)
else :
    print(score)
finally :
    print("무조건 수행합니다")