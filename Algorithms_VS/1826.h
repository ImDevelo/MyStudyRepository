#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int minRefuelStops(int N, vector<pair<int, int>>& stations, int L, int P) {
    // �������� ��ġ�� ������ ������ ����
    sort(stations.begin(), stations.end());

    // �ִ� �� (�����ҿ��� ���� �� �ִ� ���ᷮ�� ����)
    priority_queue<int> max_heap;

    // ���� ��ġ�� ���ᷮ
    int current_position = 0;
    int current_fuel = P;

    // ���� Ƚ��
    int refuel_count = 0;

    int index = 0;

    while (current_position + current_fuel < L) {
        // ���� ��ġ���� ���� ������ ��� �����Ҹ� ���� �߰�
        while (index < N && stations[index].first <= current_position + current_fuel) {
            max_heap.push(stations[index].second);
            index++;
        }

        // ���� ����ִٸ� �� �̻� �����ҿ� ������ �� ����
        if (max_heap.empty()) {
            return -1;
        }

        // ���� ���� ���Ḧ ���� �� �ִ� �����ҿ��� ����
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
