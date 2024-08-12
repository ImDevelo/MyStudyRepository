//https://www.acmicpc.net/problem/11399
#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int N;
    priority_queue<int, vector<int> , greater<int>> q;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int input;
        cin >> input;
        q.push(input);
    }

    int stack = 0, result = 0;
    while (!q.empty())
    {
        stack += q.top();
        result += stack;
        q.pop();
    }

    cout << result;
    return 0;
}