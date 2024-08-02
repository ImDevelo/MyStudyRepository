//나이트 이동
//https://www.acmicpc.net/problem/7562

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int s_r, s_c;
int t_r, t_c;

int bfs(vector<vector<bool>>& check) {
    queue<pair<pair<int, int>, int>> q;
    int dR[8] = { 2,2,1,1,-1,-1,-2,-2 };
    int dC[8] = { 1,-1,2,-2,2,-2,1,-1 };

    q.push({ {s_r,s_c}, 0 });
    check[s_r][s_c] = true;

    while (!q.empty())
    {
        int current_r = q.front().first.first;
        int current_c = q.front().first.second;
        int count = q.front().second;
        q.pop();

        if (current_r == t_r && current_c == t_c) {
            return count;
        }


        for (int i = 0; i < 8; i++) {
            int next_r = dR[i] + current_r;
            int next_c = dC[i] + current_c;

            if (next_r >= 0 && next_r < N && next_c >= 0 && next_c < N) {
                
                if (!check[next_r][next_c]) {
                    check[next_r][next_c] = true;
                    q.push({ {next_r,next_c}, count + 1 });
                    
                }
            }
        }
    }

    return 0;
}


void MySolution() {
    cin >> N;
    vector<vector<bool>> check(N, vector<bool>(N, false));

    cin >> s_r >> s_c;
    cin >> t_r >> t_c;

    cout << bfs(check) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        MySolution();
    }


}