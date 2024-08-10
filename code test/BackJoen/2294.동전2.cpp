//동전 2
//https://www.acmicpc.net/problem/2294
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	const int INF = 100001;
	int N, K;
	cin >> N >> K;

	vector<int> arr(N);
	vector<int> dp(K+1, INF);
	dp[0] = 0;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		int coin = arr[i];
		for (int k = coin; k <= K; k++) {
			dp[k] = min(dp[k], dp[k - coin] + 1);
		}
	}

	if (dp[K] < 100001) {
		cout << dp[K];
	}
	else {
		cout << -1;
	}
}


