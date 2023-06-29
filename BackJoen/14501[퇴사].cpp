//퇴사
//https://www.acmicpc.net/problem/14501
/*
dp인줄 알았으나 브로트포스 알고리즘.. 
이런 유형은 브로트포스다!
*/
#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
#define MAX 16

int n;
vector<pair<int,int>> list;
int dp[MAX] = {0};

void dfs(int day, int sum){

    for(int i=day; i < n; i++ ){
        int next_day = i + list.at(i).first;
        int sum_pay = list.at(i).second + sum;

        if(next_day <= n && (dp[next_day] < sum_pay || dp[next_day] == 0) ){
            dp[next_day] = sum_pay;
            dfs(next_day,sum_pay);
        }
            
    }
}

void MySolution(){
    cin >> n;
    for(int i=0,t,p; i<n; i++){
        cin >> t >> p;
        list.push_back({t,p});
    }
    dfs(0,0);
    cout << *max_element(dp, dp+n+1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    MySolution();
}