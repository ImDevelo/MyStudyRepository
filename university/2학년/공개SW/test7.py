A = [[1,4],
     [2,5],
     [3,6]]
B = [[12,11,10],
     [7,6,5]]


def InBise(a,b):
    ans = []
    ilen = len(a)
    jlen = len(b[0])
    klen = len(b)


    for i in range(ilen):
        ans_row = []
        for j in range(jlen):
            index = 0
            for k in range(klen):
                index += (a[i][k] * b[k][j])
            ans_row.append(index)
        ans.append(ans_row)    
    print(ans)
InBise(A,B)


