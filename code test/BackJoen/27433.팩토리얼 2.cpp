//https://www.acmicpc.net/problem/27433
#include <iostream>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;

    cin >> N;

    long long sum = 1;
    for (int i = 1; i <= N; i++) {
        sum *= i;
    }

    cout << sum;
}