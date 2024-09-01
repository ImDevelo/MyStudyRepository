//https://www.acmicpc.net/problem/2003
#include <iostream>
#include <vector>
using namespace std;

int pfx_sum[10001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	pfx_sum[0] = 0;
	for (int i = 1,input; i <= N; i++) {
		cin >> input;
		pfx_sum[i] = input + pfx_sum[i - 1];
	}

	//투 포인터
	int ans = 0;
	int start = 0, end = 1;
	while (end <= N)
	{
		int num = pfx_sum[end] - pfx_sum[start];
		if (num == M) {
			start++;
			end++;
			ans++;
		}
		else if (num < M) {
			end++;
		}
		else {
			start++;
		}
	}

	cout << ans;
}
