//토마토
//https://www.acmicpc.net/problem/7569
#include<iostream>
#include<queue>
using namespace std;


#define MAX 100
int N, M, H;
int box[MAX][MAX][MAX];
int p[6][3] = {{0,1,0},{0,0,1},{0,-1,0},{0,0,-1},{1,0,0},{-1,0,0}};



bool overflow(int h, int n, int m){
    if(h < 0 || h >= H || n < 0 || n >= N || m < 0 || m >= M){
        return false;
    }
    return true;
}


int BFS(){
    int day = 0;
    int unripenTomato = 0;
    queue<int> n, m, h;
    for(int i =0; i < H;i++){
        for(int j =0;j<N;j++){
            for(int k =0; k<M;k++){
                if(box[i][j][k] == 1){
                    h.push(i); n.push(j); m.push(k);
                }
                else if(box[i][j][k] == 0){
                   unripenTomato++;
                }
            }
        }
    }
    if(unripenTomato == 0)
        return 0;
    

    while (!n.empty())
    {
        
        int h1 = h.front();
        int n1 = n.front();
        int m1 = m.front();    
        h.pop(); n.pop(); m.pop();


        for(int i = 0; i < 6; i++){
            int h2 = h1 + p[i][0];
            int n2 = n1 + p[i][1];
            int m2 = m1 + p[i][2];

            if(overflow(h2,n2,m2)){
                if(box[h2][n2][m2] == 0 ){
                    box[h2][n2][m2] = box[h1][n1][m1] + 1;
                    h.push(h2); n.push(n2); m.push(m2);
                    unripenTomato--;

                    if(box[h2][n2][m2] > day + 1 ){
                        day = box[h2][n2][m2] - 1;
                    }
                }
            }
        }
    }
    if(unripenTomato > 0){
        return -1;
    }else if(unripenTomato == 0){
        return day;
    }
    
    
}


void MySolution(){
    cin >> M >> N >> H;
    for(int h =0; h < H;h++){
        for(int n =0;n<N;n++){
            for(int m =0; m<M;m++){
                cin >> box[h][n][m];
            }
        }
    }

    cout << BFS() << endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();

}