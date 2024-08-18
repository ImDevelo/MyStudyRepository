//https://www.acmicpc.net/problem/2580
#include <iostream>
#include <vector>
using namespace std;

int board[9][9];

bool row[9][9];  // 행 체크
bool col[9][9];  // 열 체크
bool area[9][9]; // 9x9 체크

vector<pair<int, int>> black; // 빈칸
bool find_ans = false; // 정답 찾았는가?

void DFS(int N, int count) {
    if (N == count) {
        find_ans = true;
        return;
    }

    int black_r = black[count].first;
    int black_c = black[count].second;
    int balck_a = black_r / 3 * 3 + black_c / 3;

    for (int i = 0; i < 9; i++) {
        if (!find_ans && row[black_r][i] != true && col[black_c][i] != true && area[balck_a][i] != true) {
            row[black_r][i] = true;
            col[black_c][i] = true;
            area[balck_a][i] = true;

            board[black_r][black_c] = i + 1;
            DFS(N, count + 1);
            
            row[black_r][i] = false;
            col[black_c][i] = false;
            area[balck_a][i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < 9; i++) {
        for (int j = 0, input; j < 9; j++) {
            cin >> input;
            board[i][j] = input;
            if (input != 0) {
                row[i][input - 1] = true;
                col[j][input - 1] = true;
                area[i / 3 * 3 + j / 3][input - 1] = true;
            }
            else {
                black.push_back({ i,j });
            }
        }
    }

    DFS(black.size(), 0);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }

}