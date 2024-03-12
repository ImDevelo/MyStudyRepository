#pragma once
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

int minOperations(vector<int> arr, int threshold, int d) {
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> valueOperations;

    for (int num : arr) {
        int operations = 0;
        while (num > 0) {
            valueOperations[num].push(operations);
            num /= d;
            operations++;
        }
        valueOperations[0].push(operations);
    }

    int minOps = INT_MAX;
    for (auto& entry : valueOperations) {

        if (entry.second.size() >= threshold) {
            int totalOps = 0;
            for (int i = 0; i < threshold; ++i) {
                totalOps += entry.second.top();
                entry.second.pop();
            }
            minOps = min(minOps, totalOps);
        }
    }

    return minOps == INT_MAX ? -1 : minOps;
}

void MySolution() {
    vector<int> arr1 = { 64, 30, 25, 33 };
    int threshold1 = 2;
    int d1 = 2;
    cout << minOperations(arr1, threshold1, d1) << endl; // 3

    vector<int> arr2 = { 1, 2, 3, 4 };
    int threshold2 = 4;
    int d2 = 3;
    cout << minOperations(arr2, threshold2, d2) << endl; // 6


}