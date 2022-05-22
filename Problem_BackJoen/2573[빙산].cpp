//빙산
//https://www.acmicpc.net/problem/2573
#include<iostream>
#include<queue>
using namespace std;

#define MAX 300
int ice[300][300];
int N, M;
int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int iceCount = 0;

bool meltIce(){
    bool check[MAX][MAX];
    int counting = 0;
    queue<int> R,C;

    for(int i=0; i<N;i++){
            for(int j =0; j<M;j++){
                check[i][j] =false;
            }
        }
    for(int i=1; i<N; i++){
        for(int j=0; j<M;j++){
            if(ice[i][j] != 0){
                R.push(i); C.push(j);
                check[i][j] = true;
                counting++;
                break;
            }
        }
    }

    while (!R.empty())
    {
        int r1 = R.front();
        int c1 = C.front();
        R.pop(); C.pop();

        for(int i=0; i<4;i++){
            int r2 = r1 + d[i][0];
            int c2 = c1 + d[i][1];
            //현제 위치에서 녹이기
            if(check[r2][c2] != true && ice[r2][c2] == 0 && ice[r1][c1] != 0){
                ice[r1][c1]--;
                if(ice[r1][c1] == 0){
                    iceCount--; counting--;
                }
            }
            if(check[r2][c2] != true && ice[r2][c2] != 0 ){
                check[r2][c2] = true;
                R.push(r2); C.push(c2);
                counting++;
            }
        }
    }

        
    cout << iceCount << " " << counting << "\n";
    if(iceCount != 0 && iceCount == counting){
        return true;
    }
    return false;
}

void MySolution(){
    cin >> N >> M;
    

    for(int i=0; i<N;i++){
        for(int j=0;j<M;j++){
            int temp;
            cin >> temp;
            ice[i][j] = temp;
            if(temp != 0){
                iceCount++;
            }
        }
    }
    int year = 0;
    while (true)
    {

        
        if(meltIce()){
            year++;
        }else{
            if(iceCount == 0)
                cout << 0;
            else
                cout << year;    
            break;
        }
        

    }
    
    


}




int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();

}