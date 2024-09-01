//https://www.acmicpc.net/problem/13549
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int V, E;
	cin >> V >> E;
	vector<vector<pair<int,int>>> arr(V);

	int start;
	cin >> start;


	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a - 1].push_back({ b - 1, c });
	}

	priority_queue < pair<int, int>, vector< pair<int, int>>, greater< pair<int, int>>> q;
	vector<int> ds(V, INT_MAX);

	q.push({ 0,start - 1 });
	ds[start - 1] = 0;

	while (!q.empty())
	{
		int node = q.top().second;
		int weight = q.top().first;
		q.pop();

		for (pair<int, int> value: arr[node]) {
			int next = value.first;
			int next_weight = value.second;

			if (ds[next] > next_weight + ds[node]) {
				ds[next] = next_weight + ds[node];
				q.push({ ds[next] , next });
			}
		}
	}

	for (auto v : ds) {
		if (v == INT_MAX) {
			cout << "INF\n";
		}
		else {
			cout << v << "\n";
		}
	}
}

