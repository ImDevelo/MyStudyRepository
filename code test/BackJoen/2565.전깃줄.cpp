//https://www.acmicpc.net/problem/2565
#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int>> arr;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        arr.push_back({ a,b });
    }
    sort(arr.begin(), arr.end());

    vector<int> LIS;
    for (int i = 0; i < N; i++) {
        int value = arr[i].second;
        int pos = lower_bound(LIS.begin(), LIS.end(), value) - LIS.begin();
        
        if (pos == LIS.size()) {
            LIS.push_back(value);
        }
        else {
            LIS[pos] = value;
        }
    }

    cout << N - LIS.size();

    return 0;
}
