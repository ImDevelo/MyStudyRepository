file_name = input("파일 이름을 입력하시오: ")
Alphabet = 'abcdefghijklmnopqrstuvwxyz'
count = 0

with open(file_name, "r") as f :
    text = f.read()
    text = text.lower()
    for ch in text:
        if Alphabet.find(ch) > 0:
            count += 1
 
print("알파벳 개수는", count)