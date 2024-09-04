//https://www.acmicpc.net/problem/2239
#include <iostream>
#include <vector>
using namespace std;

int arr[9][9];
bool c_row[9][9];
bool c_col[9][9];
bool c_box[3][3][9];
vector<pair<int, int>> vec;
bool isFind = false;

void sudoku(int index) {
	if (vec.size() == index) {
		isFind = true;
		return;
	}
	int r = vec[index].first;
	int c = vec[index].second;

	for (int i = 0; i < 9; i++) {
		if (!isFind && c_row[r][i] != true && c_col[c][i] != true && c_box[r/3][c/3][i] != true) {
			c_row[r][i] = true;
			c_col[c][i] = true;
			c_box[r / 3][c / 3][i] = true;
			arr[r][c] = i + 1;
			sudoku(index + 1);
			c_row[r][i] = false;
			c_col[c][i] = false;
			c_box[r / 3][c / 3][i] = false;
		}
	}


}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			char input;
			cin >> input;
			int in = input - '0';

			arr[i][j] = in;

			if (in != 0) {
				c_row[i][in-1] = true;
				c_col[j][in-1] = true;
				c_box[i / 3][j / 3][in-1] = true;
			}
			else {
				vec.push_back({ i,j });
			}
		}
	}

	sudoku(0);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << arr[i][j];
		}
		cout << "\n";
	}

}
