#파일에서 특정 단어를 다른 단어로 교체하는 프로그램을 작성하시오. 
file_name = input("파일 이름을 입력하시오: ")
word_changed = str(input("변경할 단어를 입력하시오: ")) #피변경 단어
word_replace = str(input("대체할 단어를 입력하시오: ")) #데체할 단어

with open(file_name, "rt") as file:
	x = file.read()
    
with open(file_name, "wt") as file:
    x = x.replace(word_changed,word_replace)
    file.write(x)

