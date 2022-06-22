//최소 힙
//https://www.acmicpc.net/problem/1927
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define MAX 0

void MySolution(){
    int N;
    priority_queue<int,vector<int>,greater<int>> q;

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