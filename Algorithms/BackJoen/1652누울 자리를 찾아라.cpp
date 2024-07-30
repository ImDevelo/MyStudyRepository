//누울 자리를 찾아라
//https://www.acmicpc.net/problem/1652
#include <iostream>
#include <vector>

using namespace std;

int countHorizontal(const vector<vector<char>>& room, int N) {
    int count = 0;
    
    for (int i = 0; i < N; ++i) {
        int consecutiveEmpty = 0;
        for (int j = 0; j < N; ++j) {
            if (room[i][j] == '.') {
                consecutiveEmpty++;
            } else {
                if (consecutiveEmpty >= 2) {
                    count++;
                }
                consecutiveEmpty = 0;
            }
        }
        if (consecutiveEmpty >= 2) {
            count++;
        }
    }
    
    return count;
}

int countVertical(const vector<vector<char>>& room, int N) {
    int count = 0;
    
    for (int j = 0; j < N; ++j) {
        int consecutiveEmpty = 0;
        for (int i = 0; i < N; ++i) {
            if (room[i][j] == '.') {
                consecutiveEmpty++;
            } else {
                if (consecutiveEmpty >= 2) {
                    count++;
                }
                consecutiveEmpty = 0;
            }
        }
        if (consecutiveEmpty >= 2) {
            count++;
        }
    }
    
    return count;
}

int main() {
    int N;
    cin >> N;
    
    vector<vector<char>> room(N, vector<char>(N));
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> room[i][j];
        }
    }
    
    int horizontalCount = countHorizontal(room, N);
    int verticalCount = countVertical(room, N);
    
    cout << horizontalCount << endl;
    cout << verticalCount << endl;
    
    return 0;
}
