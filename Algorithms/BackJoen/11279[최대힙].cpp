//최대 힙
//https://www.acmicpc.net/problem/11279
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void MySolution(){
    int N;
    priority_queue<int,vector<int>,less<int>> q;

    cin >> N;
    for(int i=0,temp; i<N; i++){
        cin >> temp;
        if(temp > 0){
            q.push(temp);
        }else{
            if(q.empty()){
                cout << 0 << " ";
            }else{
                cout << q.top() << " ";
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