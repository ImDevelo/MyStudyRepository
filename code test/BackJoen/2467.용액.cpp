//https://www.acmicpc.net/problem/2467
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

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

    int left = 0, right = N - 1;
    long best = 20000000002;
    int ans1 = arr[left], ans2 = arr[right];

    while (left < right) {
        long sum = arr[left] + arr[right];

        if (abs(sum) < abs(best)) {
            best = sum;
            ans1 = arr[left];
            ans2 = arr[right];
        }

        if (sum < 0) {
            left++;
        }
        else {
            right--;
        }
    }

    cout << ans1 << " " << ans2 << "\n";
    return 0;
}
