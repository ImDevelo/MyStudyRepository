//https://www.acmicpc.net/problem/1620
#include <iostream>
#include <string>
#include <unordered_map>
#include <typeinfo>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, R;
	cin >> N >> R;

	unordered_map<string, int> stringToNum;
	vector<string> numToString(N+1);

	for (int i = 1; i <= N; i++) {
		string in;
		cin >> in;
		numToString[i] = in;
		stringToNum[in] = i;
	}

	for (int i = 0; i < R; i++) {
		string in;
		cin >> in;
		
		if (isdigit(in[0])) {
			cout << numToString[stoi(in)] << "\n";
		}
		else {
			cout << stringToNum[in] << "\n";
		}
	}

}
