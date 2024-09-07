//https://www.acmicpc.net/problem/11722
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vector<int> dp(N, 1);
    dp[0] = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end());

    return 0;
}
