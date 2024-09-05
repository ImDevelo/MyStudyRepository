//https://www.acmicpc.net/problem/15663
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void DFS(const vector<int>& arr, int M, int count, vector<bool>& check, vector<int>& list, set<vector<int>>& index) {

	if (M == count) {
		index.insert(list);
		return;
	}

	for (int i = 0; i < arr.size(); i++) {
		if (!check[i]) {
			check[i] = true;
			list[count] = arr[i];
			DFS(arr, M, count + 1, check, list, index);
			check[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<int> arr(N);

	for (int i = 0, in; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	vector<bool> check(N, false);
	vector<int> ans(M);
	set<vector<int>> index;
	DFS(arr, M, 0, check, ans, index);

	for (auto s : index) {
		for (int c : s) {
			cout << c << " ";
		}
		cout << "\n";
	}
}
