//https://www.acmicpc.net/problem/10809
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str;
	cin >> str;

	vector<int> pos(26, -1);

	for (int i = 0; i < str.size(); i++) {
		int index = str[i] - 'a';
		if (pos[index] == -1) {
			pos[index] = i;
		}
	}



	for (int v : pos) {
		cout << v << " ";
	}

}
