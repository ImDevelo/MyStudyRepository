//https://www.acmicpc.net/problem/1197
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            }
            else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            }
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    bool isUnion(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E;
    cin >> V >> E;

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    for (int i = 0; i < E; i++) {
        int s, e, t;
        cin >> s >> e >> t;
        pq.push({ t, {s - 1, e - 1} });
    }

    UnionFind uf(V);
    int sum = 0;

    while (!pq.empty()) {
        int value = pq.top().first;
        pair<int, int> pos = pq.top().second;
        pq.pop();

        if (!uf.isUnion(pos.first, pos.second)) {
            uf.unite(pos.first, pos.second);
            sum += value;
        }
    }

    cout << sum << "\n";
    return 0;
}
