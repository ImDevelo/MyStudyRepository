//https://www.acmicpc.net/problem/9465
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[100000][2];
int dp[100000][2];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N;
		cin >> N;

		for (int n = 0; n < 2; n++) {
			for (int i = 0; i < N; i++) {
				cin >> arr[i][n];
			}
		}

		dp[0][0] = arr[0][0];
		dp[0][1] = arr[0][1];
		dp[1][0] = arr[1][0] + arr[0][1];
		dp[1][1] = arr[1][1] + arr[0][0];

		for (int i = 2; i < N; i++) {
			for (int j = 0; j < 2; j++) {
				dp[i][j] = max({ arr[i][j] + dp[i - 1][(j + 1) % 2],
								arr[i][j] + dp[i - 2][0],
								arr[i][j] + dp[i - 2][1] });
			}

		}

		cout << max(dp[N - 1][0], dp[N - 1][1]) << "\n";
	}

}
