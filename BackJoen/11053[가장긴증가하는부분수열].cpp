//가장 긴 증가하는 부분 수열
//https://www.acmicpc.net/problem/11053
#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 1000

void MySolution(){
    int N;
    int arr[MAX], dp[MAX];
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    for(int i= N-1; i >= 0; i--){
        dp[i] = 1;
        for(int j=i; j<N; j++){
            if(arr[i] < arr[j]){
                dp[i] = max(dp[i] , dp[j] + 1);
            }
        }
    }
    cout << *max_element(dp, dp+N);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    MySolution();
}