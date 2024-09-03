//https://www.acmicpc.net/problem/1620
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, T;
	cin >> T;

	unordered_map<string, int> dex;
	while (T--)
	{
		int N;
		cin >> N;
			
		for (int i = 0; i < N; i++) {
			string temp, s1;
			cin >> temp >> s1;
			dex[s1]++;
		}

		int sum = 1;
		for (pair<string, int> v : dex) {
			sum *= v.second + 1;
		}
		cout << sum - 1 << "\n";

		dex.clear();
	}
}
