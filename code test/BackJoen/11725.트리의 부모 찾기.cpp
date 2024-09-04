//https://www.acmicpc.net/problem/11725
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	
	vector<vector<int>> arr(N+1);
	
	for (int i = 0, a,b; i < N-1; i++) {
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	vector<int> check(N + 1, 0);
	queue<int> q;
	q.push(1);

	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		for (int next : arr[node]) {
			if (check[next] == 0) {
				check[next] = node;
				q.push(next);
			}
		}
	}

	for (int i = 2; i <= N; i++) {
		cout << check[i] << "\n";
	}
}
