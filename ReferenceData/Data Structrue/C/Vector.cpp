#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void vector_function()
{
	//백터의 초기화
	vector<int> value1(5);
	vector<int> value2 = { 1,2,3,4,5 };
	vector<int> value3;
	value3 = { 1,2,3,4,5 };
	vector<int> value4;
	value4.assign(5, 0);

	/*이차백터의 초기화*/
	vector<int> duble_value1[] = { {1,2,3},{4,5} };	// 행은 가변, 열은 고정
	vector<vector<int>> duble_value2;

	//백터 주소 반환
	 vector<int>::iterator itor1 = value2.begin(); //정순환 처음 주소
	 vector<int>::iterator itor2 = value2.end();//끝주소

	 vector<int>::reverse_iterator itor3 = value2.rbegin(); //역방향 첫주소
	 vector<int>::reverse_iterator itor4 = value2.rend(); //역방향 끝주소


	 //백터요소 접근
	 int index1 = value2.front();	//맨처음 요소
	 int index2 = value2.back();	//맨 끝 요소
	 int index3 = value2.at(1);		//범위검사 함
	 int index4 = value2[2];		//범위검사 안함

	 //백터요소 삽입
	 value2.push_back(10);
	 value2.pop_back();
	 value2.insert(value2.begin()+1, 20);
	 value2.emplace(value2.begin()+2, 30);
	 value2.emplace_back(40);
	 value2.erase(value2.begin()+3);
	 value2.erase(value2.begin(), value2.begin()+2);
	 //value2.reserve(10);
	 value2.shrink_to_fit();
	 cout << value2.size() << endl;
	 cout << value2.capacity() << endl;
	 //value2.swap(value3);


	 for_each(value2.begin(), value2.end(), [&](int& n) {cout << n << endl; });
	 //for_each(value3.begin(), value3.end(), [&](int& n) {cout << n << endl; });

}