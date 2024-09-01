//https://www.acmicpc.net/problem/9376
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

void test_case() {
	int R, C;
	cin >> R >> C;

	vector<vector<int>> arr(R, vector<int>(C));

	vector<pair<int, int>> starting;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char input;
			cin >> input;
			arr[i][j] = input;
			if (input == '$') {
				starting.push_back({ i,j });
			}
		}
	}

	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater< pair<int, pair<int, int>>>> man;
	vector<vector<int>> check(R, vector<int>(C, 0));
	int man1_door = 100000, man2_door = 100000;
	int dr[4] = { 1,-1,0,0 };
	int dc[4] = { 0,0,1,-1 };

	man.push({ 0, { starting[0].first,starting[0].second} });
	check[starting[0].first][starting[0].second] = true;

	while (!man.empty())
	{
		pair<int, int> pos = man.top().second;
		int door_c = man.top().first;
		man.pop();

		if (pos.first == 0 || pos.first == R-1 || pos.second == 0 || pos.first == C-1 ) {
			man1_door = min(man1_door, door_c);
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int nr = dr[i] + pos.first;
			int nc = dc[i] + pos.second;

			if (arr[nr][nc] != '*' && check[nr][nc] != 1 && door_c < man1_door) {
				int nd = door_c;
				if (check[nr][nc] == 0 && arr[nr][nc] == '#') {
					nd += 1;
				}
				man.push({nd, {nr,nc}});
				check[nr][nc] = 1;
			}
		}
	}

	// 사람 1 탈출 후
	// 사람 2 탈출 시작

	man.push({0,{ starting[1].first, starting[1].second }});
	check[starting[1].first][starting[1].second] = 2;

	while (!man.empty())
	{
		pair<int, int> pos = man.top().second;
		int door_c = man.top().first;
		man.pop();

		if (pos.first == 0 || pos.first == R - 1 || pos.second == 0 || pos.first == C - 1 ) {
			man2_door = min(man2_door, door_c);
			cout << man2_door <<"탈옥2! \n";
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nr = dr[i] + pos.first;
			int nc = dc[i] + pos.second;
			
			if (check[nr][nc] == 1) {
				if (arr[nr][nc] == '#') {
					door_c++;
				}

				man2_door = door_c;
				break;
			}

			if (arr[nr][nc] != '*' && check[nr][nc] != 2) {

				cout << "?" << endl;

				int nd = door_c;
				if (check[nr][nc] == 0 && arr[nr][nc] == '#' && door_c + 1 <= man2_door) {
					nd += 1;
				}
				man.push({ nd, {nr,nc} });
				check[nr][nc] = 2;
			}
		}
	}

	cout << man1_door + man2_door << "\n";
	// case 1 각자 좋은곳

	// case 2 똑같은 문

	// 각자 뚫고 가다가 만나면 ? 해당에 편승

	// 

}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		test_case();
	}
}

