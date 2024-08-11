sentence = """by the rivers of babylon, there we sat down yeah we wept,
when we remember zion.
when the wicked carried us away in captivity required from us a song
now how shall we sing the lord’s song in a strange land"""

alphabet = dict()               # 빈 사전을 생성
for c in sentence :             # (1) 위 문장(sentence)를 한 글자씩 나누어 c에 담아 for문으로 돌립니다.
    if c.isalpha() == False :   # (2) 현제 c(sentence의 n번째 문자)가 영어가 아니라면 아래는 실행하지 않고 continue합니다.
        continue    
    c = c.lower()               # (3) 영문 대문자를 소문자로 바꾸어 줍니다.(문자 통일)
    if c not in alphabet :      # (4) 딕셔너리에서 c문자가 존재하지 않다면, 딕셔너리에 c문자(key)를 추가합니다.
        alphabet[c] = 1         
    else :                      # (5) 존재한다면 해당 c문자(key)에 value값을 1증가 시킵니다.
        alphabet[c] += 1
print(alphabet)                 # (6) 딕셔너리를 출력합니다. {key(문자) : value(문자의 갯수)}