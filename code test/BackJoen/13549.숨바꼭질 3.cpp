//https://www.acmicpc.net/problem/13549
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100002

int main() {
	int N, K;
	cin >> N >> K;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
	vector<int> dp(MAX + 1, MAX);

	heap.push({ 0,N });

	while (!heap.empty())
	{
		int cnt = heap.top().first;
		int pos = heap.top().second;
		heap.pop();

		if (pos == K) {
			cout << cnt;
			break;
		}

		if (pos * 2 <= MAX && dp[pos * 2] > cnt) {
			heap.push({ cnt, pos * 2 });
			dp[pos * 2] = cnt;
		}
		if (pos + 1 <= MAX && dp[pos + 1] > cnt + 1) {
			heap.push({ cnt + 1, pos + 1 });
			dp[pos + 1] = cnt + 1;
		}
		if (pos - 1 >= 0 && dp[pos - 1] > cnt + 1) {
			heap.push({ cnt + 1, pos - 1 });
			dp[pos - 1] = cnt + 1;
		}
	}
}