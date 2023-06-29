//로봇 청소기
//https://www.acmicpc.net/problem/14503
#include<iostream>
#define MAX 50
using namespace std;

void MySolution(){
    int N, M;
    int area[MAX][MAX];
    int pos_r,pos_c,direction; //로봇 청소기 위치 , 바라보는 방향
    int cleanning = 1; //청소된 구역 수
    int d[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

    cin >> N >> M ;
    cin >> pos_r >> pos_c >> direction;
    
    for(int i =0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> area[i][j];
        }
    }
    area[pos_r][pos_c] = 2;

    // 0: 빈구역 1: 벽 2: 청소된 구역
    while (true)
    {
        int point_r = pos_r;
        int point_c = pos_c;
        bool move = false;

        for(int i=0; i<4;i++){
            direction += 1; //청소기 회전
            if(direction == 4) direction = 0;

            int next_point_r = point_r + d[direction][0];
            int next_point_c = point_c + d[direction][1];

            if(area[next_point_r][next_point_c] == 0){//만약 왼쪽(먼저 회전했으니 사실상 앞쪽)이 청소되지 않았다면 이동후 청소
                pos_r = next_point_r;
                pos_c = next_point_c;
                area[next_point_r][next_point_c] = 2;
                cleanning++;
                move = true;
                i = 4;
                continue; //회전 종료
            }
        }
        if(!move){ // 만약 회전하지 않았다면 후진
            int back_point_r = point_r - d[direction][0];
            int back_point_c = point_c - d[direction][1];
            if(area[back_point_r][back_point_c]==1){ //후진 하는 곳이 벽이라면 종료
                break;
            }
            pos_r = back_point_r;
            pos_c = back_point_c;
        }
    }
    cout << cleanning;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    MySolution();
}