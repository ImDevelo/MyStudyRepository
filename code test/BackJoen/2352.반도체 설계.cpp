//https://www.acmicpc.net/problem/2352
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

    vector<int> LST;
    for (int i = 0; i < N; i++) {
        int pos = (lower_bound(LST.begin(), LST.end(), arr[i]) - LST.begin());
        if (pos == LST.size()) {
            LST.push_back(arr[i]);

        }
        else {
            LST[pos] = arr[i];
        }
    }

    cout << LST.size();

    return 0;
}
