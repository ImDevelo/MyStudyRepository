//https://www.acmicpc.net/problem/8979
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<long long> score(N + 1);
    long long target_num = 0;
    for (int i = 1; i <= N; i++) {
        int num, a, b, c;

        cin >> num >> a >> b >> c;

        long long sum = a * 1000000000002 + b * 1000001 + c;
        score[num] = sum;
        if (num == K) {
            target_num = sum;
        }
    }

    int count = 0;
    for (int i = 1; i <= N; i++) {

        if (target_num < score[i]) {
            count++;
        }
    }

    cout << count + 1;
}