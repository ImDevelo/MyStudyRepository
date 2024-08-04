//주식
//https://www.acmicpc.net/problem/11501
#include <iostream>
#include <vector>
using namespace std;

void stock() {
    int N;
    cin >> N;

    int stock = 0;

    int count = 0;
    int prev = 0;
    int save = 0;

    int today;
    for (int i = 0; i < N; i++ ) {
        cin >> today;

        if (today < prev) {
            //즉시 판매
            stock += save;
            save = 0;
            count = 1;
        }
        else {
            //이익 축척
            int gap = today - prev;
            save += ( today - prev ) * count;
            count++;
        }
        prev = today;
    }
    stock += save;

    cout << stock << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        stock();
    }

    return 0;
}