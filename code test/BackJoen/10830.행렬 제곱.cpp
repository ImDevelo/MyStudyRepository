//https://www.acmicpc.net/problem/10830
#include <iostream>
#include <vector>
using namespace std;

#define MOD 1000

vector<vector<int>> metc(const vector<vector<int>>& arrA, const vector<vector<int>>& arrB, int N) {
	vector<vector<int>> result (N, vector<int>(N));
	for (int n = 0; n < N; n++) {
		for (int k = 0; k < N; k++) {
			int sum = 0;
			for (int m = 0; m < N; m++) {
				sum += arrA[n][m] * arrB[m][k];
			}
			result[n][k] = sum % MOD;
		}
	}
	return result;
}

void calc(const vector<vector<int>>& arr, int N, long power) {
	vector<vector<int>> result(N, vector<int>(N, 0));
	vector<vector<int>> base = arr;

	for (int i = 0; i < N; i++) {
		result[i][i] = 1;
	}

	while (power > 0)
	{
		if (power % 2 == 1) {
			result = metc(result, base, N);
		}

		base = metc(base, base, N);
		power /= 2;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	int N;
	long B;

	cin >> N >> B;
	vector<vector<int>> arr(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	

	calc(arr, N, B);

}
