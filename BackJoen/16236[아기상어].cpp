#include<iostream>
#include<utility>
#include<queue>
using namespace std;
#define MAX 20

int N, M;
int map[MAX][MAX];
int babySarke = 2;
int eat_fish = 0;
int d[4][2] = { {-1,0},{0,-1},{0,1},{1,0}};

int bfs(pair<int, int> start) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
    bool visited[MAX][MAX] = { 0 }; 
    int max_distance = 0;
    bool find_fish = false;

    q.push({ 0,{ start.first,start.second } });
    visited[start.first][start.second] = true;

    while (!q.empty())
    {
        int r_current = q.top().second.first;
        int c_current = q.top().second.second;
        int distance = q.top().first;
        
        if (max_distance < distance && find_fish) { //같은 거리안에서 가장 우선순위 높은 물고기 먹기
            while (!q.empty()){
                int r1 = q.top().second.first;
                int c1 = q.top().second.second;
                int d1 = q.top().first;
                q.pop();
                if (map[r1][c1] != 0 && map[r1][c1] < babySarke) {
                    map[r1][c1] = 0;
                    eat_fish += 1;
                    if (eat_fish == babySarke) {
                        eat_fish = 0;
                        babySarke += 1;
                    }
                    return (bfs({ r1,c1 })+d1);
                }
            }
        }
        q.pop();
        max_distance = distance; //거리값 변화 측정

        for (int i = 0; i < 4; i++) { // 물고기 탐색
            int r_next = r_current + d[i][0];
            int c_next = c_current + d[i][1];

            if (r_next >= 0 && c_next >= 0 && r_next < N && c_next < N) {
                if (map[r_next][c_next] <= babySarke && visited[r_next][c_next] == false) {//이동
                    q.push({ distance + 1, { r_next,c_next } });
                    visited[r_next][c_next] = true;
                    if (map[r_next][c_next] != 0 && map[r_next][c_next] < babySarke) { //만약 물고기가 탐색되었다면
                        find_fish = true;
                    }
                }
            }
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    pair<int, int> start;
    cin >> N;
    for (int i = 0, t; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> t;
            map[i][j] = t;
            if (t == 9) {
                start.first = i;
                start.second = j;
                map[i][j] = 0;
            }
        }
    }
    cout << bfs(start);
}