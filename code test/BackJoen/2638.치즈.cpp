//https://www.acmicpc.net/problem/2638
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void CZ_BFS(vector<vector<int>>& arr, int R, int C, int& cz_count) {
    int dr[4] = {1,-1,0,0};
    int dc[4] = {0,0,1,-1};
    queue<pair<int, int>> q;
    vector<vector<int>> check(R, vector<int>(C, 0));
    vector<pair<int, int>> discz;
    q.push({ 0,0 });
    check[0][0] = true;

    while (!q.empty())
    {
        pair<int,int> node = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = dr[i] + node.first;
            int nc = dc[i] + node.second;

            if (nr >= 0 && nc >= 0 && nr < R && nc < C && check[nr][nc] >= 0) {

                //check 0은 미탐색 -1은 공기 1~부터 접촉
                
                if (arr[nr][nc] == 0) {
                    q.push({ nr,nc });
                    check[nr][nc] = -1;
                }
                else if(arr[nr][nc] == 1){
                    check[nr][nc]++;
                    if (check[nr][nc] == 2) {
                        discz.push_back({ nr,nc });
                    }
                }
            }
        }
    }

    cz_count -= discz.size();
    for (pair<int, int> cz : discz) {
        arr[cz.first][cz.second] = 0;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int R, C, cz_count = 0;
    cin >> R >> C;
    vector<vector<int>> arr(R, vector<int>(C));

    for (int i = 0; i < R; i++){
        for (int j = 0, in; j < C; j++){
            cin >> in;
            arr[i][j] = in;
            if (in == 1) cz_count++;
        }
    }

    int ans = 0;
    while (cz_count > 0)
    {
        ans++;
        CZ_BFS(arr, R, C, cz_count);
    }

    cout << ans;
}
