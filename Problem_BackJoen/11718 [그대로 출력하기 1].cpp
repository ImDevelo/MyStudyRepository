//그대로 출력하기 1
////https://www.acmicpc.net/problem/11718
#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;

	while (true) {
		getline(cin, str);

		if (str == "")
			break;

		cout << str << endl;
	}
	return 0;
}
