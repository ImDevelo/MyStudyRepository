#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

// 1. Vector 관련 메서드
void demonstrateVector() {
	vector<int> vec = { 1, 2, 3 }; // 초기화
	vector<int> vec2(5, 10);     // 5개의 10으로 초기화
	vec.push_back(4);            // 삽입
	vec.pop_back();              // 마지막 요소 제거
	vec.insert(vec.begin() + 1, 99); // 특정 위치에 삽입
	vec.erase(vec.begin());      // 특정 위치 삭제
	cout << "Vector Size: " << vec.size() << ", Capacity: " << vec.capacity() << endl;

	vec.reserve(20);             // 용량 증가
	vec.shrink_to_fit();         // 용량 축소
	cout << "Vector Element Access: " << vec[0] << ", " << vec.at(1) << ", Front: " << vec.front() << ", Back: " << vec.back() << endl;

	sort(vec.begin(), vec.end()); // 정렬
	vector<int> vec3 = { 10, 20, 30 };
	vec.swap(vec3);               // 교환

	cout << "Vector Elements: ";
	for (int val : vec) cout << val << " ";
	cout << endl;
}

// 2. List 관련 메서드
void demonstrateList() {
	list<int> lst = { 1, 2, 3 }; // 초기화
	lst.push_back(4);          // 뒤에 삽입
	lst.push_front(0);         // 앞에 삽입
	lst.pop_back();            // 뒤에서 제거
	lst.pop_front();           // 앞에서 제거
	lst.insert(lst.begin(), 99); // 삽입
	lst.erase(lst.begin());    // 삭제

	lst.sort();                // 정렬
	lst.reverse();             // 반전

	cout << "List Elements: ";
	for (int val : lst) cout << val << " ";
	cout << endl;
}

// 3. Deque 관련 메서드
void demonstrateDeque() {
	deque<int> dq = { 1, 2, 3 }; // 초기화
	dq.push_back(4);           // 뒤에 삽입
	dq.push_front(0);          // 앞에 삽입
	dq.pop_back();             // 뒤에서 제거
	dq.pop_front();            // 앞에서 제거

	cout << "Deque Elements: ";
	for (int val : dq) cout << val << " ";
	cout << endl;
}

// 4. Set 관련 메서드
void demonstrateSet() {
	set<int> s = { 5, 3, 1, 4, 2 }; // 초기화 및 정렬
	s.insert(6);                  // 삽입
	s.erase(3);                   // 삭제

	cout << "Set Elements: ";
	for (int val : s) cout << val << " ";
	cout << endl;
}

// 5. Unordered Set 관련 메서드
void demonstrateUnorderedSet() {
	unordered_set<int> us = { 5, 3, 1, 4, 2 }; // 초기화
	us.insert(6);                            // 삽입
	us.erase(3);                             // 삭제

	cout << "Unordered Set Elements: ";
	for (int val : us) cout << val << " ";
	cout << endl;
}

// 6. Map 관련 메서드
void demonstrateMap() {
	map<int, string> m = { {1, "one"}, {2, "two"}, {3, "three"} }; // 초기화
	m[4] = "four";                                              // 삽입
	m.erase(2);                                                 // 삭제

	cout << "Map Elements: ";
	for (auto &[key, value] : m) cout << key << "->" << value << " ";
	cout << endl;
}

// 7. Unordered Map 관련 메서드
void demonstrateUnorderedMap() {
	unordered_map<int, string> um = { {1, "one"}, {2, "two"}, {3, "three"} }; // 초기화
	um[4] = "four";                                                        // 삽입
	um.erase(2);                                                           // 삭제

	cout << "Unordered Map Elements: ";
	for (auto &[key, value] : um) cout << key << "->" << value << " ";
	cout << endl;
}

// 8. String 관련 메서드
void demonstrateString() {
	string str = "hello";         // 초기화
	str += " world";              // 연결
	str.insert(5, ",");           // 삽입
	str.erase(5, 1);              // 삭제
	str.replace(0, 5, "Hi");      // 대체
	cout << "String: " << str << endl;

	cout << "Substring: " << str.substr(0, 2) << endl; // 부분 문자열
	cout << "Find 'world': " << str.find("world") << endl; // 검색

	int num = stoi("123");        // 문자열 -> 정수 변환
	string numStr = to_string(456); // 정수 -> 문자열 변환
	cout << "Converted: " << num << ", " << numStr << endl;
}

// Main 함수
int main() {
	demonstrateVector();
	demonstrateList();
	demonstrateDeque();
	demonstrateSet();
	demonstrateUnorderedSet();
	demonstrateMap();
	demonstrateUnorderedMap();
	demonstrateString();
	return 0;
}
