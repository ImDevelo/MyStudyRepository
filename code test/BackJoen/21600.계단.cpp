//계단
//https://www.acmicpc.net/problem/21600
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    
    int N;
    cin >> N;

    vector<int> v;
    vector<int> dp;

    int input;
    for (long i = 0; i < N; i++) {
        cin >> input;
        v.push_back(input);
    }
    int result = 0;
    
    dp.push_back(1);
    for (int i = 1; i < N; i++) {
        int data = min(v[i], dp[i - 1] + 1);
        dp.push_back(data);
        result = max(result, dp[i]);
    }

    cout << result << "\n";
}