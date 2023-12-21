//계단 오르기
//https://www.acmicpc.net/problem/2579
#include<iostream>
using namespace std;
#define MAX 300
int N;
int arr[MAX];
int topdown[MAX];
int best = 0;

void DFS(int count, int seq, int sum){
    if(count == N && best < sum){
        best = sum;
        return;
    }
    if(seq < 2){
        if(topdown[count] <= sum + arr[count]){
            topdown[count+1] = sum + arr[count+1];
            DFS(count + 1, seq+1, sum + arr[count]);
        }
    }
    if((count + 2) <= N){
        if(topdown[count+1] <= sum + arr[count+1]){
            topdown[count+1] = sum + arr[count+1];
            DFS(count + 2, 1 ,sum + arr[count+1]);
        }
        
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> N;

    for(int i=0; i<N; i++){
        cin >> arr[i];
        topdown[i] = 0;
    }
    DFS(0,0,0);
    cout << best;
}