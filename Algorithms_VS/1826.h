#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int minRefuelStops(int N, vector<pair<int, int>>& stations, int L, int P) {
    // 주유소의 위치와 주유량 정보를 정렬
    sort(stations.begin(), stations.end());

    // 최대 힙 (주유소에서 얻을 수 있는 연료량을 저장)
    priority_queue<int> max_heap;

    // 현재 위치와 연료량
    int current_position = 0;
    int current_fuel = P;

    // 주유 횟수
    int refuel_count = 0;

    int index = 0;

    while (current_position + current_fuel < L) {
        // 현재 위치에서 도달 가능한 모든 주유소를 힙에 추가
        while (index < N && stations[index].first <= current_position + current_fuel) {
            max_heap.push(stations[index].second);
            index++;
        }

        // 힙이 비어있다면 더 이상 주유소에 도달할 수 없음
        if (max_heap.empty()) {
            return -1;
        }

        // 가장 많은 연료를 얻을 수 있는 주유소에서 주유
        current_fuel += max_heap.top();
        max_heap.pop();
        refuel_count++;
    }

    return refuel_count;
}

int MySolution() {
    int N;
    cin >> N;

    vector<pair<int, int>> stations(N);
    for (int i = 0; i < N; ++i) {
        cin >> stations[i].first >> stations[i].second;
    }

    int L, P;
    cin >> L >> P;

    int result = minRefuelStops(N, stations, L, P);
    cout << result << endl;

}
