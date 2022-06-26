//카드 정렬하기
//https://www.acmicpc.net/problem/
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
#define MAX 100000

void MySolution(){
    int N, ans = 0;
    priority_queue<int,vector<int>,greater<int>> q;

    cin >> N;
    for(int i=0,t; i<N; i++){
        cin >> t;
        q.push(t);
    }

    if(N==1){
        cout << 0;
        return;
    }

    while (!q.empty())
    {
        int sum = q.top();
        q.pop();
        sum += q.top();
        q.pop();
        ans += sum;
        if(q.empty()){
            break;
        }
        q.push(sum);
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    MySolution();
}