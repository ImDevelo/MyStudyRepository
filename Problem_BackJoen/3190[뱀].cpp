//뱀
//https://www.acmicpc.net/problem/3190
#include<iostream>
#include<utility>
#include<queue>
using namespace std;
#define MAX 100

int N, K, L;
int ans_time = 0;
char map[MAX][MAX];
queue<pair<int, int>> snake;
queue<pair<int, int>> snake_move;
int d[4][2] = { {0,1} ,{1,0} ,{0,-1}, {-1,0} };

int HeadLooking(char ld, int look) {
    if (ld == 'L') {
        return (look - 1 >= 0) ? (look - 1) : (3);
    } else {
        return (look + 1 < 4) ? (look + 1) : 0;
    }
}

void MySolution() {
    pair<int, int> head_point = { 0,0 };
    int head_looks = 0;
    snake.push({ 0,0 });
    map[0][0] = 'S';

    while (true)
    {
        int move_point = MAX;
        pair<int, int> snake_command;
        if (!snake_move.empty()) {
            snake_command = snake_move.front();
            snake_move.pop();
            move_point = (snake_command.first - ans_time);
        }

        for (int i = 0; i < move_point; i++) {
            pair<int, int> current_head = head_point;
            current_head.first += d[head_looks][0];
            current_head.second += d[head_looks][1];
            ans_time++;
            // 뱀이 이동을 멈추는 조건은 다음과 같다.
            // 1. 벽에 부딪친 경우
            if (current_head.first < 0 || current_head.first >= N
                || current_head.second < 0 || current_head.second >= N) { 
                return;
            }
            // 2. 자신의 꼬리를 밟은 경우
            if (map[current_head.first][current_head.second] == 'S') {
                return;
            }
            // 위 조건을 성립했다면 아래 조건을 따른다.
            // 사과를 먹지 않는 경우 꼬리를 없애고 아니라면 그냥 둔다.
            if (map[current_head.first][current_head.second] != 'A') {
                pair<int,int> tail_point = snake.front();
                map[tail_point.first][tail_point.second] = '#';
                snake.pop();
            }
            //머리를 저장한다
            snake.push({ current_head.first, current_head.second });
            map[current_head.first][current_head.second] = 'S';
            head_point = { current_head.first ,current_head.second };
        }
        head_looks = HeadLooking(snake_command.second, head_looks);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> N;
    cin >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            map[i][j] = '#';
        }
    }

    for (int i = 0,r,c; i < K; i++) {
        cin >> r >> c;
        map[r-1][c-1] = 'A';
    }

    cin >> L;
    for (int i = 0, m; i < L; i++) {
        char d;
        cin >> m >> d;
        snake_move.push({ m, d });
    }

    MySolution();
    cout << ans_time;
}
