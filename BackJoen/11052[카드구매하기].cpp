//카드 구매하기
//https://www.acmicpc.net/problem/11052
#include<iostream>
using namespace std;
#define MAX 1001
int arr[MAX];
int best[MAX];
int N;

void cardCost(int n, int cost){
    if(n == N && cost > best[N]){
        best[N] = cost;
        return;
    }else if(n < N){
        for(int i=1; i<=N; i++){
            if( N >= n+i && best[n+i] < cost+arr[i] ){
                best[n+i] = cost+arr[i];
                cardCost(n+i,cost+arr[i]);
            }
            
        }
    }
}


void MySolution(){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }
    cardCost(0,0);

    cout << best[N];

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    MySolution();
}