import zipfile
def compressZip(zipname) :
    print("[%s] -> [%s] 압축 풀기...." %(zipname,zipname[0:-4]))
    with zipfile.ZipFile(zipname, 'r') as ziph :
        ziph.extractall() 
    print("압축 풀기가 끝났습니다")
zipname = input("파일이름을 입력하시오: ")
compressZip(zipname)