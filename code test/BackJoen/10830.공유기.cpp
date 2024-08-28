//https://www.acmicpc.net/problem/10830
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Check(const vector<int>& arr, int C, int gap) {
	int size = arr.size();
	int point = arr[0];
	int count = 1;

	for (int i = 1; i < size && count <= C; i++) {
		
		if (arr[i] - point >= gap) {
			point = arr[i];
			count++;
		}

		if (count >= C) {
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, C;
	cin >> N >> C;

	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	int start = 0;
	int end = (arr[N - 1] - arr[0]);
	int ans = 0;

	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (Check(arr, C, mid)) {
			ans = mid;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}

	cout << ans;
}
