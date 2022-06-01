//스타트와 링크
//https://www.acmicpc.net/problem/14889
#include<iostream>
#include<math.h>
using namespace std;
#define MAX 20

int team[MAX][MAX];
int bestTeam;
int N;
int arr[MAX];
int arr2[MAX];
int check[MAX];


/*
int getScore(int p[]){
    int a, b;
    for(int i=0; i<N/2; i++){//1213 
        for(int j=i+1; j<=N/2; j++){
            a = a[i];
            b = a[j];

            sum1 += team[a][b];
            sum1 += team[b][a];
        }
    }
}

int teamScore(){
    int sum1 = 0, sum2 = 0, cnt = 0;
    sum1 = getScore(arr);

    int arr2[MAX];
    for(int i=0; i<N; i++){
        for(int j=0; j<N/2; j++){
        }
    }




    cout << "\n" << sum1 << "/" << sum2 << "|";

    return abs(sum1-sum2);
}
*/
//조합 선출
void selectTeam(int cnt,int start, int end){

    if(cnt == N/2){
        int c = 0;
        for(int i=0; i<N; i++){
            if(check[i] != true){
                arr2[c++] = i;
            }
        }
        for(int i=0; i<cnt; i++){
            cout << arr[i] << " ";
            cout << arr2[i] << " ";
        }
        /*
        int score = teamScore();
        cout << score << "]\n";
        if(bestTeam == 0 || score < bestTeam){
            bestTeam = score;
        }
        */

        //팀 선출
    }else{
        for(int i=start; i<end ;i++){
            arr[cnt] = i;
            check[cnt] = true;
            selectTeam(cnt+1,i+1,end+1);
            check[cnt] = false;
        }
    }
}



void MySolution(){
    cin >> N;

    for(int i=0; i<N;i++){
        for(int j=0; j<N; j++){
            cin >> team[i][j];
        }
    }

    selectTeam(0,0,N/2+1);

    cout << bestTeam;


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();

}