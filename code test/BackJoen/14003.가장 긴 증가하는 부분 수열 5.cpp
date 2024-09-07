//https://www.acmicpc.net/problem/14003
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> arr(N), dp, parent(N);
    vector<int> lisIndex;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        int pos = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
        if (pos == dp.size()) {
            dp.push_back(arr[i]);
            lisIndex.push_back(i);
        }
        else {
            dp[pos] = arr[i];
            lisIndex[pos] = i;
        }

        parent[i] = pos > 0 ? lisIndex[pos - 1] : -1;
    }

    int lisLength = dp.size();
    cout << lisLength << "\n";

    int idx = lisIndex.back();
    stack<int> s;
    while (idx != -1) {
        s.push(arr[idx]);
        idx = parent[idx];
    }

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
