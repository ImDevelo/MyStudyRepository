#include <iostream>
#include <vector>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

void STLvector(){
    // 초기화 방식
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::vector<int> vec2(5, 10);
    std::vector<int> vec3(vec2);
    std::vector<int> vec4(vec3.begin(), vec3.begin() + 3);

    

    vec.push_back(1);
    vec.pop_back();
    vec.size();
    vec.empty();

    // 삽입 및 삭제
    vec.insert(vec.begin() + 2, 99);
    vec.erase(vec.begin() + 4);

    std::vector<int> vec6 = {1, 2, 3, 4, 5};
    vec6.reserve(10); // 용량을 늘림
    vec6.shrink_to_fit(); // 용량을 실제 크기에 맞게 줄임

    std::vector<int> vec9;
    vec9.assign(7, 100); // 7개의 100으로 초기화

    vector<std::pair<int, int>> vec10;
    vec10.emplace(vec10.begin(), 1, 2); // (1,2) 쌍을 vec10의 처음에 삽입

    std::vector<int> vec7 = {1, 2, 3};
    std::vector<int> vec8 = {4, 5, 6};
    vec7.swap(vec8); // vec7과 vec8의 내용을 교환


    //벡터 요소 참조
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }

    // 최종 벡터 출력
    for (int val : vec) {
        cout << val << " ";
    }
}




int main(){

    STLvector();
    
    list<int> lst = {1, 2, 3, 4, 5};
    deque<int> dq = {1, 2, 3, 4, 5};
    unordered_set<int> us = {1, 2, 3, 4, 5};

    unordered_map<int, string> um = {{1, "one"}, {2, "two"}, {3, "three"}};

    return 0;
}
