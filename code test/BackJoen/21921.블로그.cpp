//https://www.acmicpc.net/problem/21921
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N, X;
	cin >> N >> X;

	vector<int> pfx_sum(N + 1);
	pfx_sum[0] = 0;
	for (int i = 1, input; i <= N; i++) {
		cin >> input;
		pfx_sum[i] = input + pfx_sum[i - 1];
	}

	int count = 0, best = 0;
	for (int i = X; i <= N ; i++) {
		int sum = pfx_sum[i] - pfx_sum[i - X];

		if (sum > best) {
			count = 1;
			best = sum;
		}
		else if (sum == best) {
			count++;
		}
	}

	if (best == 0) {
		cout << "SAD";
	}
	else {
		cout << best << " " << count;
	}
}
