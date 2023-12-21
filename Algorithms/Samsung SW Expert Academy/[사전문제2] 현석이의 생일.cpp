// 재귀함수 DFS는 런타임오류(너무 깊이 들어감)
// stack DFS는 시간 오버
// 그렇다면 그리디 알고리즘?

#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		string number;
		string xy[2];
		int x, y;
		cin >> number;
		cin >> x >> y;
		xy[1] = to_string(max(x, y));
		xy[0] = to_string(min(x, y));

		string ans;
		stack<string> s;

		for (int i = 0; i < 2; i++) {
			if (xy[i] <= number && xy[i] != "0") {
				s.push(xy[i]);
			}
		}

		int index = 0;

		while (index < number.size())
		{
			string currentNumber = s.top();
			ans = currentNumber;
			s.pop();

			for (int i = 0; i < 2; i++) {
				string temp = currentNumber;
				temp.append(xy[i]);
				if (temp <= number) {
					s.push(temp);
				}
			}

		}

		if (ans.size() == 0)
			ans = "-1";
		
		cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;
}

/* 재귀버전
string number;
string xy[2];

string MySolution(string value, int count) 
{
	if (count == number.length()) {
		if (value > number || value == "0")
			return "-1";
		else
			return value;
	}
	else {
		string compare_number = number.substr(0,count);
		for (int i = 0; i < 2; i++) {
			if (compare_number >= value) {
				string next_number = value;
				next_number.append(xy[i]);
				string ans = MySolution(next_number, count + 1);
				if (ans != "-1")
					return ans;
			}
		}
	}
	return "-1";
}
*/