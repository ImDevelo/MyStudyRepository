#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(const vector<vector<int>>& vec, vector<vector<int>>& best, int col, int row, int sum) {

	if (row >= vec.size() || col >= vec[row].size()) {
		return;
	}

	sum += vec[row][col];
	
	if (sum > best[row][col]) {
		best[row][col] = max(best[row][col], sum);

		cout << "select" << best[row][col] << " (" << col << row << ") " << sum << endl;
		if (row == 0) {
			dfs(vec, best, col + 1, 1, sum);
		}
		else {
			dfs(vec, best, col + 1, 0, sum);
		}
		dfs(vec, best, col + 2, 0, sum);
		dfs(vec, best, col + 2, 1, sum);

	}
	
}

void caseT() {
	int N;

	cin >> N;

	vector<vector<int>> vec(2, vector<int>(N, 0));
	vector<vector<int>> best(2, vector<int>(N, 0));

	for (int i = 0, input; i < N; i++)
	{
		cin >> input;
		vec[0][i] = input;
	}
	for (int i = 0, input; i < N; i++)
	{
		cin >> input;
		vec[1][i] =input;
	}

	dfs(vec, best, 0, 0, 0);
	dfs(vec, best, 0, 1, 0);

	cout << max(best[0][N-1], best[1][N - 1]) << "\n";
}

void MySolution() {
	int T;

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		caseT();
	}
}

