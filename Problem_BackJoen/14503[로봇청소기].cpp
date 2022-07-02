//로봇 청소기
//https://www.acmicpc.net/problem/14503
#include<iostream>
#define MAX 50
using namespace std;



void MySolution(){
    int N, M;
    int area[MAX][MAX];
    int pos_r,pos_c,direction;
    int cleanning = 1; //청소된 구역
    int d[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

    cin >> N >> M ;
    cin >> pos_r >> pos_c >> direction;
    
    for(int i =0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> area[i][j];
        }
    }
    area[pos_r][pos_c] = 2;


    while (true)
    {
        int point_r = pos_r;
        int point_c = pos_c;
        bool move = false;

        //cout << "currentPoint: " << point_r << " . " << point_c << " > " << direction << " \n";

        for(int i=0; i<4;i++){
            direction += 1; //회전
            if(direction > 3) direction = 0;

            int next_point_r = point_r + d[direction][0];
            int next_point_c = point_c + d[direction][1];

            if(area[next_point_r][next_point_c] == 0){//만약 왼쪽(사실 앞쪽)이 청소되지 않았다면 
                //cout << "cleanPoint " << next_point_r <<" "<< next_point_c <<"\n";
                pos_r = next_point_r;
                pos_c = next_point_c;
                area[next_point_r][next_point_c] = 2;
                cleanning++;
                i=4; move = true;
                continue;
            }
        }
        if(!move){
            
            int back_point_r = point_r - d[direction][0];
            int back_point_c = point_c - d[direction][1];
            //cout << "backPoint " << back_point_r << " " << back_point_c << endl;
            if(area[back_point_r][back_point_c]==1){
                break;
            }
            pos_r = back_point_r;
            pos_c = back_point_c;
        }
        /*
        for(int i=0; i<N;i++){
            for(int j=0; j<M; j++){
                cout << area[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        */
    }
    cout << cleanning;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    MySolution();
}