//https://www.acmicpc.net/problem/14940
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int R, C;
	cin >> R >> C;

	pair<int, int> start;
	vector<vector<int>> arr(R, vector<int>(C));
	for (int i = 0; i < R; i++) {
		for (int j = 0, in; j < C; j++) {
			cin >> in;
			arr[i][j] = in;
			if (in == 2) {
				start = { i, j };
			}
		}
	}

	vector<vector<bool>> check(R, vector<bool>(C, false));
	queue<pair<int,int>> q;
	q.push(start);
	arr[start.first][start.second] = 0;
	check[start.first][start.second] = true;

	int count = 1;
	int dr[4] = {0,0,1,-1};
	int dc[4] = { 1,-1,0,0 };

	while (!q.empty())
	{
		int size = q.size();

		while (size--)
		{
			pair<int,int> pos = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nr = pos.first + dr[i];
				int nc = pos.second + dc[i];

				if (nr >=0 && nr < R && nc >= 0 && nc < C) {
					if (arr[nr][nc] == 1 && check[nr][nc] == false) {
						check[nr][nc] = true;
						arr[nr][nc] = count;
						q.push({ nr,nc });
					}
				}
			}
		}
		count++;
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0, in; j < C; j++) {
			if (arr[i][j] == 0 || check[i][j]) {
				cout << arr[i][j] << " ";
			}
			else {
				cout << "-1 ";
			}
		}
		cout << "\n";
	}

}
