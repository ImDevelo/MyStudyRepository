//https://www.acmicpc.net/problem/16139
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str;
	cin >> str;

	vector<vector<int>> arr(26, vector<int>(str.size()));

	for (int i = 0; i < 26; i++) {
		arr[i][0] = (str[0] - 'a') == i;
	}

	for (int i = 1; i < str.size(); i++) {
		for (int j = 0; j < 26; j++) {
			arr[j][i] = arr[j][i - 1];
		}
		arr[str[i] - 'a'][i] += 1;
	}

	int qurey;
	cin >> qurey;
	for (int i = 0; i < qurey; i++) {
		int range1, range2;
		char c;
		cin >> c >> range1 >> range2;

		cout << arr[c - 'a'][range2] - ((range1 > 0 )?  arr[c - 'a'][range1 -1] : 0) << "\n";
	}
}
