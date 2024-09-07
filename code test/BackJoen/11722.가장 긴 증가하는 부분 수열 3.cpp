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
    

    vector<int> LIS;
    LIS.push_back(arr[0]);
    for (int i = 1; i < N; i++) {
        

        if (LIS.back() < arr[i]) {
            LIS.push_back(arr[i]);
        }
        else {
            auto a = lower_bound(LIS.begin(), LIS.end(), arr[i]);
            *a = arr[i];
        }
    }

    cout << LIS.size();

    return 0;
}
