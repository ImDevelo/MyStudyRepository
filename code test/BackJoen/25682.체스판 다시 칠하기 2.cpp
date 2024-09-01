//https://www.acmicpc.net/problem/25682
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int R, C, K;
	cin >> R >> C >> K;
	vector<vector<bool>> arr(R+1, vector<bool>(C+1));

	//격자면 ture 아면 false
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			char input;
			cin >> input;
			if ((i + j) % 2) {
				arr[i][j] = (input == 'W');
			}else {
				arr[i][j] = (input == 'B');
			}
		}
	}

	// 격자 일치 누적합
	vector<vector<int>> pfx_sum(R+1, vector<int>(C+1));
	for (int i = 0; i <= R; i++) pfx_sum[i][0] = 0;
	for (int i = 0; i <= C; i++) pfx_sum[0][i] = 0;

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			pfx_sum[i][j] = arr[i][j] + pfx_sum[i - 1][j] + pfx_sum[i][j - 1] - pfx_sum[i - 1][j - 1];
		}
	}

	// 누적합 계산 (B,W 역전 값도 비교)
	int best_min = K * K;
	for (int i = K; i <= R; i++) {
		for (int j = K; j <= C; j++) {
			int sum = pfx_sum[i][j] - pfx_sum[i - K][j] - pfx_sum[i][j - K] + pfx_sum[i - K][j - K];
			best_min = min({ best_min, sum, (K * K) - sum });
		}
	}

	cout << best_min;

}

