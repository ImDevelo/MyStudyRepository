//정수 삼각형
//https://www.acmicpc.net/problem/1932
#include<iostream>
#include<utility>
#include<vector>
using namespace std;
int N, best = 0;
vector<pair<int,int>>* v;


void DFS(int layer, int sector, int sum){
    if(layer == N){
        if(best < sum){
            best = sum;
        }
        return;
    }
    if(v[layer][sector].second == 0 || v[layer][sector].second < sum ){
        v[layer][sector].second = sum;
        sum += v[layer][sector].first;
    
        DFS(layer+1, sector, sum);
        DFS(layer+1, sector+1, sum);
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> N;

    v = new vector<pair<int,int>>[N];
    for(int i=0; i<N;i++){
        for(int j=0, temp; j<=i;j++){
            cin >> temp;
            v[i].push_back({temp,0});
        }
    }
    DFS(0,0,0);
    cout << best;
}