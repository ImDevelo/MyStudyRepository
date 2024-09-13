//https://www.acmicpc.net/problem/2473
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#define MAX 400000000000

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N; 
    vector<long> arr(N);
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    long best = MAX;
    long ans[3];
    for (int mid = 1; mid < N-1; mid++) {
        
        int start = 0, end = N - 1;
        while (start < end)
        {
            long sum = arr[start] + arr[end] + arr[mid];

            if (abs(sum) < best) {
                best = abs(sum);
                ans[0] = arr[start];
                ans[1] = arr[mid];
                ans[2] = arr[end];
            }

            if (sum < 0) {
                if (start < mid - 1) {
                    start++;
                }
                else {
                    end--;
                }
            }
            else {
                if (end > mid + 1) {
                    end--;
                }
                else {
                    start++;
                }
            }
        }
    }

    for (long n : ans) {
        cout << n << " ";
    }

    return 0;
}
