with open("log/count_log.txt", "r") as f :
    text = f.read()
    word_list = text.split(" ") # 빈 칸 기준으로 단어를 분리
    line_list = text.split("\n") # 한 줄씩 분리
print("총 글자의 수: ", len(text))
print("총 단어의 수: ", len(word_list))
print("총 줄의 수: ", len(line_list))