//절대값 힙
//https://www.acmicpc.net/problem/11286
#include<iostream>
#include<utility>
#include<queue>
#include<math.h>
using namespace std;

void MySolution(){
    int N;
    priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>>> q;
    cin >> N;
    for(int i=0,temp; i<N; i++){
        cin >> temp;

        if(temp != 0){
            q.push({abs(temp),temp});
        }else{
            if(q.empty()){
                cout << 0 << " ";
            }else{
                cout << q.top().second << " ";
                q.pop();
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    MySolution();
}