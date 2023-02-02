#include<iostream>
#define MAX 20
using namespace std;

int R, C, Answer;
char map[MAX][MAX];
bool check[26];
int d[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

void DFS(int x, int y, int count){
    Answer = max(Answer, count);
    
    for (int i = 0; i < 4; i++){
        int next_r = x + d[i][0];
        int next_c = y + d[i][1];

        if (next_r >= 0 && next_c >= 0 && next_r < R && next_c < C){
            int point = (map[next_r][next_c] - 65);

            if (check[point] == false){
                check[point] = true;
                DFS(next_r, next_c, count + 1);
                check[point] = false;
            }
        }
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> R >> C;

        Answer = 0;
        for (int i = 0; i < 26; i++)
            check[i] = false;
        
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> map[i][j];
            }
        }
        check[map[0][0] - 65] = true;
        DFS(0, 0, 1);

        printf("#%d %d\n", test_case, Answer);
    }
    return 0;
}