#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 1001

int N;
int best = 0;
int bestcost[MAX][3];
int color[MAX][3];
int notSame[3][2] = {{1,2},{0,2},{0,1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> color[i][j];
            bestcost[i][j] = 0;
        }
    }
    bestcost[0][0] = color[0][0];
    bestcost[0][1] = color[0][1];
    bestcost[0][2] = color[0][2];

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            int selectLowColor = min(bestcost[i - 1][notSame[j][0]], bestcost[i - 1][notSame[j][1]]);
            bestcost[i][j] = color[i][j] + selectLowColor;
        }
    }
    cout << min(min(bestcost[N-1][0], bestcost[N-1][1]), bestcost[N-1][2]);
}

int N;
int dp[1000][3];

int AthorSolution() {
    cin>>N;

    for(int i = 0; i < N; i++) {
            cin>>dp[i][0]>>dp[i][1]>>dp[i][2];
    }
    for(int i = 1; i < N; i++) {
        dp[i][0] = min(dp[i][0] + dp[i-1][1], dp[i][0] + dp[i-1][2]);
        dp[i][1] = min(dp[i][1] + dp[i-1][0], dp[i][1] + dp[i-1][2]);
        dp[i][2] = min(dp[i][2] + dp[i-1][0], dp[i][2] + dp[i-1][1]);
    }
    cout<<min(dp[N-1][0], min(dp[N-1][1], dp[N-1][2]));
}