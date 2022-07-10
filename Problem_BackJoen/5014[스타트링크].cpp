//
//https://www.acmicpc.net/problem/
#include<iostream>
#include<queue>
using namespace std;
#define MAX 1000001

int max_floor, start, goal;
int up, down;
int dp[MAX] = { 0 };

void BFS_queue() {
    queue<int> q;
    
    q.push(start);
    dp[start] = 1;

    while (!q.empty()) {
        int node = q.front();
        int count = dp[node];

        q.pop();

        if (node == goal) {
            cout << (dp[node]-1);
            return;
        }
        if (node + up <= max_floor && up != 0) {
            if((dp[node + up] == 0 || dp[node + up] > count)){
                dp[node + up] = count + 1;
                q.push(node + up);
            }
            
        }
        if (node - down > 0  && down != 0) {
            if( (dp[node - down] == 0 || dp[node - down] > count)){
                dp[node - down] = count + 1;
                q.push(node - down);
            }
        }
    }
    cout << "use the stairs";
    return;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    cin >> max_floor >> start >> goal >> up >> down;
    BFS_queue();
}