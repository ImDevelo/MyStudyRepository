//차이를 최대로
//https://www.acmicpc.net/problem/10819
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
int best = 0;
int arr[8];
int value[8];
bool check[8];

void dfs(int count) {

	if (count == N) {
		int sum = 0;
		// 최대값 계산
		for (int i = 0; i < N - 1; i++) {
			sum += abs(value[i] - value[i + 1]);
		}
		best = max(sum , best);
		return;
	}

	for (int i = 0; i < N; i++) {
		if (check[i] != true) {
			check[i] = true;
			value[count] = arr[i];
			dfs(count + 1);
			check[i] = false;
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
 
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	
	dfs(0);
	
	cout << best;
}
