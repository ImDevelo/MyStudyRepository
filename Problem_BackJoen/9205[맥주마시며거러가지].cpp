//맥주마시며 걸어가기
//https://www.acmicpc.net/problem/9205
#include<iostream>
#include<utility>
#include<vector>
#include<math.h>
using namespace std;
#define MAX 102

vector<pair<int, int>> street;
pair<int, int> goal,start;


bool reachToGoal(pair<int,int> start, pair<int,int> goal) {
    if ((abs(start.first - goal.first) + abs(start.second - goal.second)) <= 1000) return true;
    return false;
}

bool dfs(pair<int,int> current_point, bool visited[MAX]) {
    if (current_point == goal) {
        return true;
    }
    for (int i = 1; i < street.size(); i++) {
        pair<int, int> next_point = street.at(i);
        if (visited[i] != true && reachToGoal(current_point, next_point)) {
            visited[i] = true;
            return dfs(next_point, visited);
        }
    }
    return false;
}


void MySolution() {
    int N, a, b;
    bool visited[MAX] = {0};

    cin >> N >> a >> b;
    start = { a,b };
    street.push_back(start);
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        street.push_back({ a,b });
    }
    cin >> a >> b;
    goal = { a,b };
    street.push_back(goal);
    
    if (dfs(start,visited))  cout << "happy\n";
    else cout << "sad\n";

    street.clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        MySolution();
    }
}