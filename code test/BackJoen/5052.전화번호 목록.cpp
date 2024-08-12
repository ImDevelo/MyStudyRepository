//https://www.acmicpc.net/problem/5052
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

void test_case() {
    int N;
    cin >> N;

    vector<string> arr;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        arr.push_back(str);
    }

    sort(arr.begin(), arr.end());

    bool consistency = true;
    for (int i = 0; i < arr.size() - 1; i++) {
        if (strncmp(arr[i].c_str(), arr[i + 1].c_str(), min(arr[i].size(), arr[i + 1].size()))== 0) {
            consistency = false;
            break;
        }
    }

    if (consistency)
        cout << "YES" << "\n";
    else
        cout << "NO" << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        test_case();
    }
}