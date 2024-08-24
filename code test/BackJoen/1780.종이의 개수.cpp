//https://www.acmicpc.net/problem/1780
#include <iostream>
#include <vector>
using namespace std;

bool check(const vector<vector<int>>& arr, int size, int r, int c) {
    for (int i = r; i < r + size; i++) {
        for (int j = c; j < c + size; j++) {
            if (arr[i][j] != arr[r][c]) {
                return false;
            }
        }
    }
    return true;
}

void split(const vector<vector<int>>& arr, int size, int r, int c, int count[3]) {
    if (size == 1 || check(arr, size, r, c)) {
        count[arr[r][c] + 1]++;
        return;
    }

    int split_size = size / 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int rr = r + i * split_size;
            int cc = c + j * split_size;
            split(arr, split_size, rr, cc, count);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, count[3] = { 0,0,0 };

    cin >> N;
    vector<vector<int>> arr(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    split(arr, N, 0, 0, count);

    cout << count[0] << " " << count[1] << " " << count[2];
}
