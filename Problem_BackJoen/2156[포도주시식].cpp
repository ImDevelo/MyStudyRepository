//포도주 시식
//https://www.acmicpc.net/problem/2156
#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 10001

void MySolution(){
    int N;
    int arr[MAX];
    int dp[MAX];
    cin >> N;

    arr[0] = 0;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }

    for(int i=1; i<=N; i++){
        if(i < 3){ // 3 이전값에 대한 초기값 설정
            dp[i] = arr[i] + arr[i-1];
        }else{ //   
            dp[i] = max(max(arr[i] + dp[i-2], arr[i] + arr[i-1] + dp[i-3]), dp[i-1]);
        }
    }
    cout << dp[N];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    MySolution();
}