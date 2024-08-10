//구슬탈출4
//https://www.acmicpc.net/problem/13462
#include<iostream>
#include<queue>
#include<utility>
#include<set>
using namespace std;
#define MAX 10

char map[MAX][MAX];
pair<int, int> red_start;
pair<int, int> blue_start;
pair<int, int> hole;

int LocationCode(pair<int,int> red, pair<int,int> blue) {
    return red.first * 1000 + red.second * 100 + blue.first * 10 + blue.second;
}

int bfs() {
    // << 파란구슬, 빨간구슬>, <상하/좌우방향, 판을움직인횟수>>
    queue<pair<pair<pair<int, int>, pair<int, int>>, pair<bool, int>>> q;
    set<int> visited;
    int d[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

    q.push({ {{red_start.first,red_start.second},{blue_start.first,blue_start.second}},{true,1} });
    q.push({ {{red_start.first,red_start.second},{blue_start.first,blue_start.second}},{false,1} });
    visited.insert(LocationCode(red_start, blue_start));

    while (!q.empty())
    {
        pair<int, int> red_current = q.front().first.first; //현제 빨간구슬 위치
        pair<int, int> blue_current = q.front().first.second; //현제 파란구슬 위치
        bool direct = q.front().second.first; // 상하혹은 좌우로 움직였는가?
        int counting = q.front().second.second; // 판 움직인 횟수
        q.pop();

        for (int i = direct; i < 4; i += 2) { //방향: 0-북 / 1-동 / 2-남 / 3-서
            pair<int, int> red_next = red_current;
            pair<int, int> blue_next = blue_current;

            //구슬 움직임 (true면 움직이는 중 / false면 이동완료 )
            bool red_moveing = true;
            bool blue_moveing = true;

            //구슬 구멍에 들어갔는가?
            bool red_in_hole = false;
            bool blue_in_hole = false;

            while (red_moveing || blue_moveing) //구슬이 모두 멈출때까지 loop (여기 while문은 마음에 안듬)
            {
                pair<int, int> red_moving_point = { red_next.first + d[i][0], red_next.second + d[i][1] };
                pair<int, int> blue_moving_point = { blue_next.first + d[i][0], blue_next.second + d[i][1] };
                // 구슬이 구멍에 들어갔는지 판별
                if (red_moveing && map[red_moving_point.first][red_moving_point.second] == 'O') {
                    red_moveing = false;
                    red_in_hole = true;
                    red_next = { 0,0 };
                }
                if (blue_moveing && map[blue_moving_point.first][blue_moving_point.second] == 'O') {
                    blue_moveing = false;
                    blue_in_hole = true;
                    blue_next = { 0,0 };
                }
                // 구슬이 이동할 수 없다면
                if (red_moveing && map[red_moving_point.first][red_moving_point.second] != '.') {
                    red_moveing = false;
                }
                if (blue_moveing && map[blue_moving_point.first][blue_moving_point.second] != '.') {
                    blue_moveing = false;
                }
                //구슬이 서로 겹치는 경우
                if (!red_moveing && blue_moving_point == red_next) {
                    blue_moveing = false;
                }
                if (!blue_moveing && red_moving_point == blue_next) {
                    red_moveing = false;
                }
                //구슬이 멈추지 않았다면 계속 이동
                if (red_moveing) {
                    red_next = red_moving_point;
                }
                if (blue_moveing) {
                    blue_next = blue_moving_point;
                }
            }


            if (red_in_hole && !blue_in_hole) { //성공!
                return counting;
            }
            else if (blue_in_hole) { //이런 실패!
                continue;
            }
            else { // 다음 케이스
                auto it = visited.insert(LocationCode(red_next, blue_next));
                if (it.second) {
                    q.push({ {red_next, blue_next} ,{ !direct , counting + 1} });
                }
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int R, C;
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char input_char;
            cin >> input_char;

            if (input_char == 'O') {
                hole = { i,j };
            }
            else if (input_char == 'R') {
                red_start = { i,j };
                input_char = '.';
            }
            else if (input_char == 'B') {
                blue_start = { i,j };
                input_char = '.';
            }

            map[i][j] = input_char;
        }
    }
    cout << bfs();
}