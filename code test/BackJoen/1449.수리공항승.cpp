//https://www.acmicpc.net/problem/1449
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int N, L;
    cin >> N >> L;

    vector<bool> arr(1001, false);
    int max_num = 0;
    for (int i = 0, t; i < N; i++) {
        cin >> t;
        arr[t] = true;
        max_num = max(t, max_num);
    }

    int count = 0;
    for (int i = 1; i <= max_num; i++) {
        if (arr[i] == true) {
            i += (L-1);
            count++;
        }
    }

    cout << count;
}