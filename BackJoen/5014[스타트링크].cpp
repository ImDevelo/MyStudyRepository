//스타트링크
//https://www.acmicpc.net/problem/5014
#include<iostream>
#include<queue>
#include<utility>
using namespace std;
#define MAX 1000001

int max_floor, start, goal;
int up, down;

void BFS_queue(){
    queue<pair<int,int>> q;
    bool visited[MAX] = {false};
    q.push({start,0});
    visited[start] = true;

    while (!q.empty())
    {
        int node = q.front().first;
        int count = q.front().second;
        q.pop();

        if(node == goal){
            cout << count;
            return;
        }

        if(up > 0 && node + up <= max_floor && visited[node + up] == false){
            q.push({node + up, count + 1});
            visited[node + up] = true;
        }
        if(down > 0 && node - down > 0 && visited[node - down] == false){
            q.push({node - down, count + 1});
            visited[node - down] = true;
        }
    }
    cout << "use the stairs";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    cin >> max_floor >> start >> goal >> up >> down;
    BFS_queue();
}