dic = { 'boy' : '소년', 'school': '명지', 'lecture' : 'python' }
print(dic)
dic['boy'] = '남자아이'
dic['girl'] = '여자아이'
print(dic)
print(dic.keys())
print(dic.values())
print(dic.items())
del dic['lecture']               # 삭제
print(dic)