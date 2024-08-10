//플로이드
//https://www.acmicpc.net/problem/11404
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
#define MAX 100
#define INF 10000000


int N, M;
int bus[MAX][MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> N >> M;

    vector<vector<int>> bus(N, vector<int>(N, INF));
   
    for (int i = 0, src, dest, cost; i < M; i++) {
        cin >> src >> dest >> cost;

        if (bus[src-1][dest-1] != 0 && bus[src-1][dest-1] <= cost) {
            continue;
        }
        bus[src-1][dest-1] = cost;
    }

    // 알고리즘
    for (int lay = 0; lay < N; lay++) {
        for (int src = 0; src < N; src++) {
            for (int dest = 0; dest < N; dest++) {
                bus[src][dest] = min(bus[src][dest], bus[src][lay] + bus[lay][dest]);
            }
        }
    }

    // 출력
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (r == c || bus[r][c] >= INF) {
                bus[r][c] = 0;
            }
            cout << bus[r][c] << " ";
        }
        cout << "\n";
    }
}