//숨바꼭질 2
//https://www.acmicpc.net/problem/12851

#include <iostream>
#include <queue>
using namespace std;
#define MAX 100001

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int N, K;

    cin >> N >> K;

    int method_count = 0;
    int min_second = 0;

    queue<pair<int, int>> q;
    int check[MAX] = { 0 };

    q.push({ N, 1});

    while (!q.empty())
    {
        int pos = q.front().first;
        int time = q.front().second;
        q.pop();
        
        //목표
        if (pos == K) {
            if (method_count == 0) {
                min_second = time;
            }
            method_count++;
            continue;
        }

        // 조건 초과
        if (method_count != 0 && min_second <= time) {
            continue;
        }

        // 2배 조건
        if (pos * 2 < MAX) {
            if (check[pos * 2] == 0 || check[pos * 2] >= time) {
                check[pos * 2] = time;
                q.push({ pos * 2, time + 1 });
            }
        }

        // 증가 조건
        if (pos < K) {
            if (check[pos + 1] == 0 || check[pos + 1] >= time) {
                check[pos + 1] = time;
                q.push({ pos + 1, time + 1 });
            }
        }

        // 감소 조건
        if (pos > 0) {
            if (check[pos - 1] == 0 || check[pos - 1] >= time ) {
                check[pos - 1] = time;
                q.push({ pos - 1 ,time + 1 });
            }
        }
    }


    cout << min_second - 1 << " " << method_count << "\n";
}