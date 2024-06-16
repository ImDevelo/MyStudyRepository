#pragma once
/*
// ����https://www.acmicpc.net/problem/10816

���� ī��� ���� �ϳ��� ������ �ִ� ī���̴�. ����̴� ���� ī�� N���� ������ �ִ�. ���� M���� �־����� ��, �� ���� �����ִ� ���� ī�带 ����̰� �� �� ������ �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

ù° �ٿ� ����̰� ������ �ִ� ���� ī���� ���� N(1 �� N �� 500,000)�� �־�����. 
��° �ٿ��� ���� ī�忡 �����ִ� ������ �־�����. ���� ī�忡 �����ִ� ���� -10,000,000���� ũ�ų� ����, 10,000,000���� �۰ų� ����.
��° �ٿ��� M(1 �� M �� 500,000)�� �־�����. ��° �ٿ��� ����̰� �� �� ������ �ִ� ���� ī������ ���ؾ� �� M���� ������ �־�����, �� ���� �������� ���еǾ��� �ִ�. 
�� ���� -10,000,000���� ũ�ų� ����, 10,000,000���� �۰ų� ����.

�Է�)
10
6 3 2 10 10 10 -10 -10 7 3
8
10 9 -5 2 3 4 5 -10

���)
3 0 0 1 2 0 0 2

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findFirstOccurrence(const vector<int>& arr, int A) {
	int left = 0, right = arr.size() - 1;
	int result = -1;  // A�� �迭�� ���� ��츦 ����� �ʱⰪ

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (arr[mid] == A) {
			result = mid;
			right = mid - 1;  // �� ���� �ε����� ã�� ���� ��� ������ Ž��
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


