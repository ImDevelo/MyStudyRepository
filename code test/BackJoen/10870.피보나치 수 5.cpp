//피보나치 수 5 
//https://www.acmicpc.net/problem/10870
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int arr[21];
    int N;

    cin >> N;

    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i <= N; i++) {
        arr[i] = arr[i - 2] + arr[i - 1];
    }

    cout << arr[N];


    return 0;
}