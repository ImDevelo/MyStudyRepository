//듣보잡
//https://www.acmicpc.net/problem/1764
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;

	cin >> N >> M;

	unordered_set<string> set;

	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		set.insert(str);
	}

	vector<string> db_list;
	for (int i = 0; i < M; i++) {
		cin >> str;

		if (!(set.find(str) == set.end())) {
			db_list.push_back(str);
			
		}
	}

	int size = db_list.size();
	cout << size << "\n";
	sort(db_list.begin(), db_list.end());
	for (int i = 0; i < size; i++) {
		cout << db_list[i] <<"\n";
	}
}

