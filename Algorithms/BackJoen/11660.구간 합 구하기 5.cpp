//구간 합 구하기
//https://www.acmicpc.net/problem/11660
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> setPrefixSum(vector<vector<int>> board, int N) {
    vector<vector<int>> prefix(N + 1, vector<int>(N + 1, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            prefix[i][j] = board[i - 1][j - 1] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
        }
    }
    return prefix;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> vec(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> vec[i][j];
        }
    }

    vector<vector<int>> prefixSum;
    prefixSum = setPrefixSum(vec, N);

    for (int i = 0; i < M; i++) {
        int x1, x2, y1, y2, value;
        cin >> x1 >> y1 >> x2 >> y2;

        value = prefixSum[x2][y2] - prefixSum[x1 - 1][y2] - prefixSum[x2][y1 - 1] + prefixSum[x1 - 1][y1 - 1];

        cout << value << "\n";
    }

}