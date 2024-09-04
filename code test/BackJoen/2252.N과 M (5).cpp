//https://www.acmicpc.net/problem/2252
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void DFS(const vector<int>& arr, vector<bool>& check, int M, int count, vector<int>& ans) {

	if (count >= M) {
		for (int i = 0; i < M; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < arr.size(); i++) {
		if (check[i] == false) {
			ans[count] = arr[i];
			check[i] = true;
			DFS(arr, check, M, count+1, ans);
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
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());
	vector<bool> check(N, false);
	vector<int> temp(M);

	DFS(arr, check, M, 0, temp);

}
