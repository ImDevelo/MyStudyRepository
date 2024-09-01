//https://www.acmicpc.net/problem/2559
#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector<int> arr(N+1);
	vector<int> sum(N + 1, 0);

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		sum[i] = arr[i] + sum[i - 1];
	}

	int best = INT_MIN;
	for (int i = 1; i <= N-K + 1; i++) {
		best = max(best, sum[i + K - 1] - sum[i - 1]);
	}

	cout << best;

}

