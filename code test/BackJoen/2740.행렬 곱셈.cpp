//https://www.acmicpc.net/problem/2740
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, M, K;

	cin >> N >> M;
	vector<vector<int>> arrA(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arrA[i][j];
		}
	}

	cin >> M >> K;
	vector<vector<int>> arrB(M, vector<int>(K));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			cin >> arrB[i][j];
		}
	}

	vector<vector<int>> result(N, vector<int>(K));
	for (int n = 0; n < N; n++) {
		for (int k = 0; k < K; k++) {
			for (int m = 0; m < M; m++) {
				result[n][k] += arrA[n][m] * arrB[m][k];
			}
		}
	}

	for (int n = 0; n < N; n++) {
		for (int k = 0; k < K; k++) {
			cout << result[n][k] << " ";
		}
		cout << "\n";
	}

}
