// 수 정렬하기3
// https://www.acmicpc.net/problem/10989
#include<iostream>
using namespace std;
int arr[10001], temp;

void MySolution() {
    int N, i, j;

    cin >> N;
    for (i = 0; i < 10001; i++) {
        arr[i] = 0;
    }

    for (i = 0; i < N; i++) {
        cin >> temp;
        arr[temp]++;
    }

    for (i = 0; i < 10001; i++) {
        for (j = 0; j < arr[i]; j++) {
            cout << i << " ";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();
}