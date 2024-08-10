//https://www.acmicpc.net/problem/2660
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int BFS(vector<vector<int>> & gp, int N, int start) {
    queue<int> q;
    vector<bool> check(N, false);

    q.push(start);
    check[start] = true;

    int count = 0;
    while (!q.empty())
    {
        int size = q.size();
        
        for (int i = 0; i < size; i++) {
            int node = q.front();
            q.pop();
            for (int next : gp[node]) {
                
                if (check[next] == false) {
                    q.push(next);
                    check[next] = true;
                }
            }
        }
        count++;
    }
    return count - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    
    int N;
    cin >> N;
    vector<vector<int>>gp(N);

    while (true)
    {
        int node, target;

        cin >> node >> target;
        if (node == -1) {
            break;
        }
        gp[node - 1].push_back(target - 1);
        gp[target - 1].push_back(node - 1);
    }

    vector<pair<int,int>> result;

    for (int i = 0; i < N; i++) {
        int d = BFS(gp, N, i);
        result.push_back({ d, i + 1 });
    }

    sort(result.begin(), result.end());

    int max_num = result[0].first;

    vector<int> ans;
    for (int i = 0; i < N; i++) {
        if (result[0].first < result[i].first) {
            break;
        }
        ans.push_back(result[i].second);
    }

    cout << max_num << " " << ans.size() << "\n";
    for (int n : ans) {
        cout << n << " ";
    }
}