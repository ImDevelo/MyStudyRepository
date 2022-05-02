#include<iostream>
#include<list>
#include<algorithm>
using namespace std;


// STL : 리스트

// 특징 - 삽입,삭제가 빠름

int main(){
    list<int> plist;
    list<int>::iterator itr_first = plist.begin();
    list<int>::iterator itr_end = plist.end();

    //인덱스 삽입
    plist.push_back(1);
    plist.push_back(2);
    plist.push_back(3);
    plist.push_front(0);

    plist.insert(itr_first++,5);

    //인덱스 삭제
    plist.pop_front();
    plist.pop_back();
    plist.erase(--itr_end);
    //인덱스
    plist.size();
    plist.empty();
    //출력
    
    for(itr_first=plist.begin(); itr_first !=plist.end(); itr_first++) { 
        cout << *itr_first << endl; // 원소 삭제후 리스트: 22 33 44 
    }
}
