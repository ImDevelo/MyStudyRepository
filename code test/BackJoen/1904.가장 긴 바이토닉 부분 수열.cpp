//https://www.acmicpc.net/problem/1904
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MOD 15746

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> arr(N);
    vector<int> dp_inc(N, 1);
    vector<int> dp_dec(N, 1);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = i; j >= 0; j--) {
            if (arr[i] > arr[j]) {
                dp_inc[i] = max(dp_inc[i], dp_inc[j] + 1);
            }
        }
    }

    for (int i = N-1; i >= 0; i--) {
        for (int j = i; j < N; j++) {
            if (arr[i] > arr[j]) {
                dp_dec[i] = max(dp_dec[i], dp_dec[j] + 1);
            }
        }
    }


    int best = 0;
    for (int i = 0; i < N; i++) {
        best = max(dp_inc[i] + dp_dec[i], best);
    }
    cout << best - 1;
}