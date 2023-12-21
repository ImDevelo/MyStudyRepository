//책 나눠주기
//https://www.acmicpc.net/problem/9576
#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define MAX 1000

void MySolution(){
    int N, M;
    bool check[MAX];
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    cin >> N >> M;

    int a,b;
    for(int i=0; i<M; i++){
        cin >> a >> b;
        q.push({b-a},a); //ab간격, 시작점
    }

    for(int i=0; i<M; i++){
        //가장 작은 값 오픈
        //가장 작은 값에 따라 숫자 지정
        // 3 4 true;
        // 2 4 2에다
        // 2 4 3
        q.top();
        q.pop();


    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        MySolution();
    }
}