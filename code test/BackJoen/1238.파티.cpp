//https://www.acmicpc.net/problem/1238
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, X;
	cin >> N >> M >> X;

	vector<vector<int>> floyd(N, vector<int>(N, 1000000000));
	for (int i = 0; i < M; i++) {
		int a, b, t;
		cin >> a >> b >> t;
		floyd[a-1][b-1] = t;
	}

	for (int i = 0; i < N; i++) floyd[i][i] = 0;

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
			}
		}
	}

	int best = 0;
	for (int i = 0; i < N; i++) {
		best = max(best, floyd[i][X - 1] + floyd[X - 1][i]);
	}
	cout << best;
}
