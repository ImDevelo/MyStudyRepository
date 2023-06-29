//스타트와 링크
//https://www.acmicpc.net/problem/14889
#include<iostream>
#include<math.h>
using namespace std;
#define MAX 20

int N;
int bestScore = -1;
int team[MAX][MAX];
int selectTeam[MAX];
int NotselectTeam[MAX];

int TeamScore(int arr[]){
    int sum = 0;
    for(int i=0; i<N/2; i++){
        for(int j=i+1; j<N/2; j++){
            sum += team[arr[i]][arr[j]];
            sum += team[arr[j]][arr[i]];
        }
    }
    return sum;
}

void DFS(int count, int start){
    if(count == N/2){
        int index1 = 0, index2 = 0;
        for(int i=0; i<N;i++){
            if(selectTeam[index1] == i){
                index1++;
            }else{
                NotselectTeam[index2] = i;
                index2++;
            }
        }
        int score = abs(TeamScore(selectTeam) - TeamScore(NotselectTeam));
        if(bestScore == -1 || score < bestScore){
            bestScore = score;
        }
        return;
    }
    for(int i=start; i<N; i++){
        selectTeam[count] = i;
        DFS(count+1, i+1);
    }
}

void MySolution(){
    cin >> N;
    for(int i=0; i<N;i++){
        for(int j=0; j<N; j++){
            cin >> team[i][j];
        }
    }
    DFS(0,0);
    cout << bestScore;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();
}