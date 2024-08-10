//10026.적록색약
//https://www.acmicpc.net/problem/10026
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(const vector<vector<char>> arr, vector<vector<int>>& check, pair<int, int> start ,int N, bool rg) {
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	char color = arr[start.first][start.second];

	queue<pair<int, int>> q;
	
	q.push(start);
	check[start.first][start.second] = true;
	
	while (!q.empty())
	{
		int current_r = q.front().first;
		int current_c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_r = current_r + dx[i];
			int next_c = current_c + dy[i];

			if (next_r >= 0 && next_r < N && next_c >= 0 && next_c < N) {

				if (check[next_r][next_c] == false ) {
					char current_color = arr[next_r][next_c];

					if (color == current_color) {
						check[next_r][next_c] = true;
						q.push({ next_r, next_c });
					}
					else if (!rg && (color == 'R' || color == 'G') && (current_color == 'R' || current_color == 'G')) {
						check[next_r][next_c] = true;
						q.push({ next_r, next_c });
					}
				}
			}
		}
	}
}


int main() {

	int N;
	cin >> N;
	vector<vector<char>> arr(N, vector<char>(N));
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	int area1 = 0, area2 = 0;
	// 적록 색약
	vector<vector<int>> check1(N, vector<int>(N, false));
	vector<vector<int>> check2(N, vector<int>(N, false));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			//정상
			if (check1[i][j] == false) {
				bfs(arr, check1, { i,j }, N, true);
				area1++;
			}
			//적록색약
			if (check2[i][j] == false) {
				bfs(arr, check2, {i,j} , N, false);
				area2++;
			}
		}
	}

	cout <<  area1 << " " << area2;
}