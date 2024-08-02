#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> vect[1001];
int visited[1001];
int N, M;

void BFS(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (q.size() != 0)
    {
        int current = q.front();
        q.pop();
        for (int i = 0; i < vect[current].size(); i++)
        {
            if (visited[vect[current][i]] == 0)
            {
                visited[vect[current][i]] = 1; 
                q.push(vect[current][i]);
            }
        }
    }
}

int main()
{
    int cnt = 0;
    int u, v;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        vect[u].push_back(v);
        vect[v].push_back(u);
    }

    for (int i = 1; i <= N; i++)
    {
        if (visited[i] == 0)
        {
            BFS(i);
            cnt++;
        }
    }
    cout << cnt;
}