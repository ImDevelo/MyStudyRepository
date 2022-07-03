#include<iostream>
#include<set>
using namespace std;

int main(){

    //set의 생성
    set<int> s1;
    set<int> s2(3);
    set<int> s3(s1);

    //주소값 호출
    s1.begin();
    s1.end();
    s1.rbegin();
    s1.rend();

    //원소 삽입/제거/크기
    set<int>::iterator iter; int i;
    s1.clear();
    s1.empty();
    s1.count(i);
    s1.insert(i); 
    //중복 불가, 삽입 성공여부는 
    s1.insert(iter,i);
    s1.erase(iter);
    s1.erase(iter, iter);
    s1.find(i);
    s2.swap(s1);


    


}