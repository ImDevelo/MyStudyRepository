file_name = input("파일 이름을 입력하시오: ")
word_name = input("찾을 단어를 입력하시오: ")
with open(file_name, "r") as f :
    text = f.read()
    text = text.lower()
    pos = text.find(word_name)
    count = 0
    while pos != -1 :
        count += 1
        pos = text.find(word_name, pos+1)
print("개수는", count)