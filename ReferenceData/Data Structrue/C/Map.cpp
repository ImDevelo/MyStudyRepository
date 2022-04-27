#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

void map_function() {

	// 맵의 초기화
	map<char, int> value1;
	value1['a'] = 1;
	map<char, int> value2(value1);


	// 맵 반복자
	value1.begin();
	value1.end();
	value1.rbegin();
	value1.rend();
	value1.cbegin();
	value1.cend();
	value1.cbegin();
	value1.crend();

	// 맵 용량
	value1.empty(); //비어있다면 true, 아니라면 false
	value1.size();
	value1.max_size();

	
	//맵 요소 접근
	value1['a'];
	value1.at('a');

	//map의 삽입 삭제
	value1.insert(pair<char, int>('b',10));
	value1.insert({ 'c',2 });
	value1.emplace('d',100);
	
	map<char, int>::iterator itr = value1.find('c');
	value1.emplace_hint(itr, 'c', 22);
	value1.erase('c');
	value1.erase(value1.find('d'), value1.end());
	
	value1.swap(value2);
	value1.clear();
}