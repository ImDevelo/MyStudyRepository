//가장 큰 증가하는 부분 수열
//https://www.acmicpc.net/problem/11055
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	int best = 0;
	cin >> N;

	vector<int> arr(N);
	vector<int> dp(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}


	for (int i = 0; i < N; i++) {
	
		dp[i] = arr[i];

		int good = 0;
		for (int k = 0; k < i; k++) {
			if ( arr[k] < arr[i]) {
				good = max(good, dp[k]);
			}
		}
		dp[i] += good;

		best = max(best, dp[i]);
	}
	
	cout << best << endl;
}


