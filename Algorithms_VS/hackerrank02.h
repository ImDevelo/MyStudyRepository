#pragma once
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<vector<int>> dist;

void bfs(int start, int n) {
    vector<int> d(n + 1, -1);
    queue<int> q;
    q.push(start);
    d[start] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (d[neighbor] == -1) {
                d[neighbor] = d[node] + 1;
                q.push(neighbor);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        dist[start][i] = d[i];
    }
}

int numberOfWays(vector<vector<int>> roads) {
    int n = roads.size() + 1;
    adj.resize(n + 1);
    dist.resize(n + 1, vector<int>(n + 1, -1));

    for (const auto& road : roads) {
        adj[road[0]].push_back(road[1]);
        adj[road[1]].push_back(road[0]);
    }

    for (int i = 1; i <= n; ++i) {
        bfs(i, n);
    }

    int ways = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            for (int k = j + 1; k <= n; ++k) {
                if (dist[i][j] == dist[j][k] && dist[j][k] == dist[i][k]) {
                    ++ways;
                }
            }
        }
    }

    return ways;
}

void MySolution() {
    vector<vector<int>> roads1 = {
        {1, 2}, {2, 5}, {3, 4}, {4, 5}, {5, 6}, {7, 6}
    };

    vector<vector<int>> roads2 = {
        {1, 2}, {2, 3}, {3, 4}, {4, 5}
    };

    cout << numberOfWays(roads1) << endl;  // Expected output: 2
    cout << numberOfWays(roads2) << endl;  // Expected output: 0

}