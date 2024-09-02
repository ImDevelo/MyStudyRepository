//https://www.acmicpc.net/problem/2167
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N, T;
	cin >> N;
	vector<int> arr(N + 1);
	arr[0] = 0;
	for (int i = 1, input; i <= N; i++) {
		cin >> input;
		arr[i] = input + arr[i - 1];
	}

	cin >> T;
	for (int i = 0; i < T; i++) {
		int a, b;
		cin >> a >> b;

		cout << arr[b] - arr[a - 1] << "\n";
	}

}
