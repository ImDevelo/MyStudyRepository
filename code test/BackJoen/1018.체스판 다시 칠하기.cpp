//체스판 다시 칠하기
//https://www.acmicpc.net/problem/1018
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<bool>> check(N, vector<bool>(M));

    char input;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            cin >> input;
            if ((r % 2 == 0 && c % 2 == 1) || (r % 2 == 1 && c % 2 == 0)) {
                check[r][c] = (input == 'B');
            }
            else {
                check[r][c] = (input == 'W');
            }
        }
    }

    vector<vector<int>> prefixSum(N + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            prefixSum[i][j] = check[i - 1][j - 1] + prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
        }
    }

    const int MAX_MODIFY = 64;
    int result = 0;

       

    for (int i = 8; i <= N; i++) {
        for (int j = 8; j <= M; j++) {
            int value = 0;

            value = prefixSum[i][j] - prefixSum[i - 8][j] - prefixSum[i][j - 8] + prefixSum[i - 8][j - 8];
            
            result = max({ result, value, MAX_MODIFY - value });
        }
    }

    cout << MAX_MODIFY - result << "\n";

}