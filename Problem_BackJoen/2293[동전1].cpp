//동전1
//https://www.acmicpc.net/problem/2293
#include <iostream>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;
    int dp[100001];
    int coin[101];

    for(int i=1; i<=N; i++){
        cin >> coin[i];
    }

    dp[0]=1;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(j -coin[i] >=0) 
                dp[j] = dp[j] + dp[j-coin[i]];
        }
    }

    cout << dp[M];
    return 0;
}
