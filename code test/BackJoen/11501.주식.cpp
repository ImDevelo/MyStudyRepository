//https://www.acmicpc.net/problem/11501
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<ll> arr(N);
        ll ans = 0;
        
        for (int i = N - 1; i >= 0; i--) {
            cin >> arr[i];
        }

        int max_point = 0;
        ll stock = 0;
        for (int i = 1; i < N; i++) {
            if (arr[max_point] < arr[i]) {
                max_point = i;
            }
            else {
                stock += (arr[max_point] - arr[i]);
            }
        }

        cout << stock << endl;
    }
}
