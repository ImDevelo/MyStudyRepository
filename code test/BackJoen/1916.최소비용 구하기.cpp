//https://www.acmicpc.net/problem/1916
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<pair<int,int>>>g(N + 1);

    for (int i = 0; i < M; i++)
    {
        int s, e, t;
        cin >> s >> e >> t;

        g[s].push_back({e,t});
    }

    int start, end;
    cin >> start >> end;

    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vector<int> distance(N + 1, INT_MAX);
    
    q.push({ 0, start});
    distance[start] = 0;

    while (!q.empty())
    {
        int node = q.top().second;
        int value = q.top().first;
        q.pop();

        if (value > distance[node]) continue;

        for (auto n : g[node]) {
            int next_node = n.first;
            int next_weight = n.second + value;

            if (next_weight < distance[next_node]) {
                distance[next_node] = next_weight;
                q.push({ next_weight, next_node });
            }
        }
    }

    cout << distance[end];

}



