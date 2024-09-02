//https://www.acmicpc.net/problem/2003
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int R, C, T;
	cin >> R >> C;

	vector<vector<int>> pfx_sum(R + 1, vector<int>(C + 1));
	for (int i = 0; i < R; i++) pfx_sum[i][0] = 0;
	for (int i = 0; i < C; i++) pfx_sum[0][i] = 0;

	for (int i = 1; i <= R; i++) {
		for (int j = 1, input; j <= C; j++) {
			cin >> input;
			pfx_sum[i][j] = input + pfx_sum[i - 1][j] + pfx_sum[i][j - 1] - pfx_sum[i - 1][j - 1];
		}

	}

	cin >> T;
	for (int i = 0; i < T; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		int sum = pfx_sum[c][d] - pfx_sum[a-1][d] - pfx_sum[c][b-1] + pfx_sum[a-1][b-1];
		cout << sum << "\n";
	}
}
