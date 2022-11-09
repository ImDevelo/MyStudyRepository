def Cal(A, B):
    gop = 0
    result = 0
    an=[]
    for k in range(3):
        answer=[]
        for i in range(0,3):
            result = 0
            for j in range(0,2):
                gop = (A[k][j]*B[j][i])
                result = result + gop
            answer.append(result)
        an.append(answer)
    return an
a = [ [ 1, 4 ], [ 2, 5 ], [ 3, 6 ]]
b = [[ 12, 11, 10 ], [7, 6, 5]]
print("계산 결과 : {0}".format(Cal(a,b)))