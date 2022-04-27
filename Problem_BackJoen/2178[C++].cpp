#include <iostream>
#include <algorithm>
using namespace std;

int N, M; // 세로 가로

bool overflow_arr(int x, int y) {
    if (x < 0 || x >= M) {
        return false;
    }
    else if (y < 0 || y >= N) {
        return false;
    }
    return true;
}



void find_rood(int x, int y, int* map[], int distance) {
    map[x][y] = distance;

    if (overflow_arr(x + 1, y) && map[y][x + 1] != 0 && map[y][x + 1] >= distance) { // 오른쪽
        find_rood(x + 1, y, map, distance + 1);
    }
    if (overflow_arr(x, y + 1) && map[y + 1][x] != 0 && map[y + 1][x] >= distance) { //아래쪽
        find_rood(x, y + 1, map, distance + 1);
    }
    if (overflow_arr(x - 1, y) && map[y][x - 1] != 0 && map[y][x - 1] >= distance) { //왼쪽
        find_rood(x - 1, y, map, distance + 1);
    }
    if (overflow_arr(x, y - 1) && map[y - 1][x] != 0 && map[y - 1][x] >= distance) { //위쪽
        find_rood(x, y - 1, map, distance + 1);
    }
    return;
}


int main() {
    
    cin >> N >> M;

    int** map = new int*[N];
    for (int i = 0; i < N; i++) {
        map[i] = new int[M];
    }

    int temp;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    
    find_rood(0, 0, map, 1);

    cout << map[N-1][M-1] <<endl;


    return 0;
}