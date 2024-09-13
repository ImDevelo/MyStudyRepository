//https://www.acmicpc.net/problem/3273
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1000000

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, X;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cin >> X;
    sort(arr.begin(), arr.end());

    int start = 0, end = N - 1;
    int count = 0;
    while (start <= end)
    {
        int sum = arr[start] + arr[end];

        if (sum == X) {
            count++;
            start++; end--;
        }
        else if (sum - X < 0) {
            start++;
        }
        else {
            end--;
        }
    }

    cout << count;

    return 0;
}
