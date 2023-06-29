//맥주마시며 걸어가기
//https://www.acmicpc.net/problem/9205
#include<iostream>
#include<utility>
#include<queue>
#include<math.h>
using namespace std;
#define MAX 102


bool reachToGoal(pair<int,int> s, pair<int,int> g) {
    if ((abs(s.first - g.first) + abs(s.second - g.second)) <= 1000) return true;
    return false;
}

void MySolution() {
    int N, a, b;
    bool visited[MAX] = {0};
    pair<int, int> street[MAX];
    pair<int, int> goal,start;

    cin >> N >> a >> b;
    start = {a,b};
    street[0] = start;
    int i = 1;
    for(i=1; i<=N;i++){
        cin >> a >> b;
        street[i] = {a,b};
    }
    cin >> a >> b;
    goal = {a,b};
    street[i] = goal;

    queue<pair<int,int>> q;
    q.push(start);
    visited[0] = true;

    while (!q.empty())
    {
        pair<int,int> current_point = q.front();
        pair<int,int> next_point;
        q.pop();
        
        if(current_point == goal){
            cout << "happy\n";
            return;
        }

        for(int i=1; i<=N+1; i++){
            next_point = street[i];
            if(reachToGoal(current_point,next_point) && visited[i] == false){
                q.push(next_point);
                visited[i] = true;
            }
        }
    }
    cout << "sad\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        MySolution();
    }
}