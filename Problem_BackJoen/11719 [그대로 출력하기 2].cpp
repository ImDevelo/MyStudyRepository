//그래로 출력하기 2
////https://www.acmicpc.net/problem/11719
#include <iostream>
#include <string>
using namespace std;


int main() {
	string str;

	while (true) {
		getline(cin, str);

		if (cin.eof())
			break;

		cout << str << endl;
	}
	return 0;
}
