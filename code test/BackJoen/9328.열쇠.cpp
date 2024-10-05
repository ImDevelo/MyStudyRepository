//https://www.acmicpc.net/problem/9328
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

void TestCase() {
    int R, C, ans = 0;
    cin >> R >> C;

    vector<vector<char>> arr(R, vector<char>(C));
    vector<vector<bool>> check(R, vector<bool>(C, false));
    vector<bool> key(26, false);
    queue<pair<int, int>> q;
    unordered_map<int, vector<pair<int, int>>> door;
    int dr[4] = { 1, -1, 0, 0 };
    int dc[4] = { 0, 0, 1, -1 };

    // ���� �Է� �ޱ�
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
            // �����ڸ����� Ž���� ������ �� �ִ� �� ť�� �ֱ�
            if (i == 0 || j == 0 || i == R - 1 || j == C - 1) {
                if (arr[i][j] != '*') {
                    q.push({ i, j });
                    check[i][j] = true;
                }
            }
        }
    }

    // ������ �ִ� ���� �Է� �ޱ�
    string str;
    cin >> str;
    if (str != "0") {
        for (char c : str) {
            key[c - 'a'] = true;
        }
    }

    while (!q.empty()) {
        pair<int,int> pos = q.front();
        int r = pos.first, c = pos.second;
        q.pop();

        char place = arr[r][c];

        // ���� �߰�
        if (place == '$') {
            ans++;
        }
        // ���� �߰�
        else if (place >= 'a' && place <= 'z') {
            key[place - 'a'] = true;
            if (door.find(place - 'a') != door.end()) {
                for (auto pos : door[place - 'a']) {
                    q.push(pos);
                }
                door.erase(place - 'a');
            }
        }
        // �� �߰�
        else if (place >= 'A' && place <= 'Z') {
            if (!key[place - 'A']) {
                door[place - 'A'].push_back({ r, c });
                continue;
            }
        }

        // �����¿�� �̵�
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nc >= 0 && nr < R && nc < C && !check[nr][nc] && arr[nr][nc] != '*') {
                check[nr][nc] = true;
                q.push({ nr, nc });
            }
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        TestCase();
    }

    return 0;
}
