//https://www.acmicpc.net/problem/12015
#include <iostream>
#include <vector>
using namespace std;

int index_binary(const vector<int>& arr, int target) {
	int left = 0;
	int right = arr.size();
	int ans = target;

	while (left <= right)
	{
		int mid = (right + left) / 2;

		if (arr[mid] >= target) {
			ans = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> arr(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	vector<int> LST;
	LST.push_back(arr[0]);
	for (int i = 1; i < N; i++) {
		int num = arr[i];
		if (LST.back() < num) {
			LST.push_back(num);
			continue;
		}
		else {
			int index = index_binary(LST, num);
			LST[index] = num;
		}
	}

	cout << LST.size();
}
