#pragma once
/*
// 문제https://www.acmicpc.net/problem/10816

숫자 카드는 정수 하나가 적혀져 있는 카드이다. 상근이는 숫자 카드 N개를 가지고 있다. 정수 M개가 주어졌을 때, 이 수가 적혀있는 숫자 카드를 상근이가 몇 개 가지고 있는지 구하는 프로그램을 작성하시오.

첫째 줄에 상근이가 가지고 있는 숫자 카드의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 
둘째 줄에는 숫자 카드에 적혀있는 정수가 주어진다. 숫자 카드에 적혀있는 수는 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다.
셋째 줄에는 M(1 ≤ M ≤ 500,000)이 주어진다. 넷째 줄에는 상근이가 몇 개 가지고 있는 숫자 카드인지 구해야 할 M개의 정수가 주어지며, 이 수는 공백으로 구분되어져 있다. 
이 수도 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다.

입력)
10
6 3 2 10 10 10 -10 -10 7 3
8
10 9 -5 2 3 4 5 -10

출력)
3 0 0 1 2 0 0 2

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findFirstOccurrence(const vector<int>& arr, int A) {
	int left = 0, right = arr.size() - 1;
	int result = -1;  // A가 배열에 없는 경우를 대비한 초기값

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (arr[mid] == A) {
			result = mid;
			right = mid - 1;  // 더 작은 인덱스를 찾기 위해 계속 왼쪽을 탐색
		}
		else if (arr[mid] < A) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	return result;
}

void MySolution() {
	int M, N;

	
	cin >> N;
	vector<int> number_index(N);
	for (int i = 0; i < N; i++) {
		cin >> number_index[i];
	}

	cin >> M;
	vector<int> search_index(M);
	for (int j = 0; j < M; j++) {
		cin >> search_index[j];
	}

	sort(number_index.begin(), number_index.end());


	for (int k = 0; k < N; k++) {
		cout << number_index[k] << " ";
	}


	for (int s = 0; s < M; s++) {

		int index = findFirstOccurrence(number_index, search_index[s]);

		if (index == -1) {
			cout << 0 << " ";
		}
		else {

		}
	}

}


