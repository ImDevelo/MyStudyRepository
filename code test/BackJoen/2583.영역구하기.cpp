//영역 구하기
//https://www.acmicpc.net/problem/2583
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 101

int R, C, N;
bool map[MAX][MAX];
int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int BFS(int rstart, int cstart){
    int area = 1;
    queue<int> r,c;    
    r.push(rstart); c.push(cstart);
    map[rstart][cstart] = true; 

    while (!r.empty())
    {
        int r1 = r.front();
        int c1 = c.front();

        r.pop(); c.pop();

        for(int i=0; i<4;i++){
            int r2 = r1 + d[i][0];
            int c2 = c1 + d[i][1];

            if(r2 >=0 && c2 >= 0 && r2 < R && c2 < C){
                if(map[r2][c2] != true){
                    r.push(r2); c.push(c2);
                    map[r2][c2] = true;
                    area++;
                }
            }
        }
    }
    return area;
}

void MySolution(){
    vector<int> v;
    cin >> R >> C >> N;

    int x1,x2,y1,y2;
    for(int i=0; i<N; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j=x1; j<x2; j++ ){
            for(int k=y1; k<y2; k++){
                map[k][j] = true;
            }
        }
    }

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(map[i][j] != true){
                v.push_back(BFS(i,j));
            }
        }
    }
    
    sort(v.begin(), v.end());

    cout << v.size() << "\n";
    vector<int>::iterator itr;
    for(itr = v.begin(); itr != v.end(); itr++){
        cout << *itr << " ";
    }
    
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    MySolution();
}