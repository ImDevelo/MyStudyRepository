//오르막 수
//https://www.acmicpc.net/problem/11057
#include <iostream>
#define MOD 10007
using namespace std;

long long index[1001][10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < 10; i++) {
        index[0][i] = 1;
    }

    for (int i = 1; i <= N; i++) {
        index[i][0] = 1;
        for (int j = 1; j < 10; j++) {
            index[i][j] = (index[i][j - 1] + index[i - 1][j]) % MOD;
        }
    }

    cout << (index[N][9] % MOD) << endl;

}