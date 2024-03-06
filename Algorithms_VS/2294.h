#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void MySolution() {
    int N, K;
    cin >> N >> K;
    vector<vector<int>> dp(K+1, vector<int>(N+1,0));
    vector<int> coin(N, 0);

    for (int i = 1; i <= N; i++) {
        cin >> coin[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; i++) {
            


        }
    }

}

