def print_string(*my_text):
    result = ' '
    print(my_text)
    for s in my_text:
        result = result + s
    return result
    
print(print_string('파이썬은', '정말', '재미있다'))