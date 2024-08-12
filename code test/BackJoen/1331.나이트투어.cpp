//https://www.acmicpc.net/problem/1331
#include <iostream>
#include <string>
#include <cmath>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    bool arr[6][6];
    string str[37];

    for (int i = 0; i < 36; i++) {
        cin >> str[i];
    }

    // 나이트 이동 검사
    bool valid = true;
    for (int i = 0; i < 37; i++) {
        string prev = str[i % 36];
        string next = str[(i + 1) % 36];

        int ap = abs(prev[0] - next[0]);
        int num = abs(prev[1] - next[1]);

        if (!((ap == 2 && num == 1 )||(ap == 1 && num == 2))) {
            valid = false;
            break;
        }
        arr[prev[0] - 'A'][prev[1] - '1'] = true;
    }

    // 모두 방문 여부 체크
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (arr[i][j] != true) {
                valid = false;
                break;
            }
        }
    }

    if (valid)
        cout << "Valid" << "\n";
    else
        cout << "Invalid" << "\n";

}