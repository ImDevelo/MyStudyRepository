# copy_and_rename.py

import re
import os

def extract_number_from_line(file_path):
    """
    파일의 첫 줄에서 숫자를 추출합니다.
    """
    with open(file_path, 'r') as file:
        first_line = file.readline().strip()
        match = re.search(r'//https://www.acmicpc.net/problem/(\d+)', first_line)
        if match:
            return match.group(1)
    return None

def copy_and_rename(source_file_path, destination_dir, number, description):
    """
    소스 파일을 지정된 디렉토리로 복사하고, 파일 이름을 새로 지정합니다.
    """
    if number is None:
        print("첫 줄에서 숫자를 추출할 수 없습니다.")
        return
    
    # 새 파일 이름 생성
    file_name = f"{number}.{description}.cpp"
    destination_file_path = os.path.join(destination_dir, file_name)

    # 파일 복사
    try:
        with open(source_file_path, 'r') as source_file:
            content = source_file.read()

        with open(destination_file_path, 'w') as destination_file:
            destination_file.write(content)

        print(f"파일이 성공적으로 {destination_file_path}에 복사되었습니다.")
    except Exception as e:
        print(f"오류 발생: {e}")

if __name__ == "__main__":
    import sys
    
    source_file = r"C:\Users\imdls\Documents\Project\CodeTest\codetest.py"
    destination_dir = r"C:\Users\imdls\Documents\Project\My-Study-Repository\code test\BackJoen"

    # 첫 줄에서 숫자 추출
    number = extract_number_from_line(source_file)
    
    if number is None:
        print("소스 파일에서 숫자를 추출하지 못했습니다.")
        sys.exit(1)

    # 사용자 입력 받기
    description = input("파일 이름에 추가할 설명을 입력하세요 (띄어쓰기도 가능): ").strip()

    # 파일 복사 및 이름 변경
    copy_and_rename(source_file, destination_dir, number, description)
