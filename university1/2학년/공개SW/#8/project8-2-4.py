import zipfile
def compressZip(zipname, filename) :
    print("[%s] -> [%s] 압축...." %(filename, zipname))
    with zipfile.ZipFile(zipname, 'w') as ziph :
        ziph.write(filename)
    print("압축이 끝났습니다")
filename = input("파일이름을 입력하시오: ")
zipname = filename + '.zip'
compressZip(zipname, filename)