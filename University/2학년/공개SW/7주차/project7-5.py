text = input()
if text.isdigit() == False :
    try :
        raise Exception("입력 문자열이 숫자가 아닙니다.")
    except Exception :
        print("예외가 일어났습니다.")