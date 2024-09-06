//https://www.acmicpc.net/problem/9251
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str1, str2;
	cin >> str1 >> str2;

	int size1 = str1.size(), size2 = str2.size();
	vector<vector<int>> dp(size1 + 1, vector<int>(size2+1));
	for (int i = 0; i <= size1; i++) dp[i][0] = 0;
	for (int i = 0; i <= size2; i++) dp[0][i] = 0;

	for (int i = 1; i <= size1; i++) {
		for (int j = 1; j <= size2; j++) {
			if (str1[i-1] == str2[j-1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[size1][size2];
}
