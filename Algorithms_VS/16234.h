#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool makeAli(vector<vector<int>>& land, vector<vector<bool>>& check, pair<short, short> start_point, int L, int R) 
{
	int d[4][2] = { {0,1}, {1,0}, {-1,0}, {0,-1} };
	int land_size = land.size();
	queue<pair<short, short>> q;
	vector<pair<short, short>> ali;
	int sum_people = 0;

	q.push(start_point);
	ali.push_back(start_point);
	sum_people = land[start_point.first][start_point.second];
	check[start_point.first][start_point.second] = true;

	while (!q.empty())
	{
		short current_point_r = q.front().first;
		short current_point_c = q.front().second;
		int current_people_count = land[current_point_r][current_point_c];

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			short next_point_r = current_point_r + d[i][0];
			short next_point_c = current_point_c + d[i][1];

			if (next_point_r >= 0 && next_point_r < land_size && next_point_c >= 0 && next_point_c < land_size && !check[next_point_r][next_point_c]) {
				
				int next_people_count = land[next_point_r][next_point_c];
				int gap = abs(current_people_count - next_people_count);

				if ( gap >= L && gap <= R) {
					sum_people += land[next_point_r][next_point_c];
					check[next_point_r][next_point_c] = true;
					q.push({ next_point_r, next_point_c });
					ali.push_back({ next_point_r, next_point_c });
				}
			}
		}
	}

	int mean = sum_people / ali.size(); // 평군 계산

	// 인구이동
	if (ali.size() > 1) {

		for (pair<short, short> point : ali) {
			land[point.first][point.second] = mean;
		}

		return true;
	}
	return false;
}

void MySolution() {
	int N, L, R;

	cin >> N >> L >> R;

	vector<vector<int>> land(N, vector<int>(N, 0));
	

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
		{
			int input;
			cin >> input;
			land[i][j] = input;
		}
	}

	bool flag = true;
	int day = 0;

	while (flag && day <= 2000)
	{
		flag = false;
		int land_size = land.size();
		vector<vector<bool>> check(land_size, vector<bool>(land_size, false));
		
		for (int i = 0; i < land_size; i++) {
			for (int j = 0; j < land_size; j++)
			{
				if (check[i][j]) {
					continue;
				}
				flag = max(flag, (makeAli(land, check, { i,j }, L, R)));
			}
		}

		if (flag) {
			day++;
		}
	}
	cout << day << "\n";
}