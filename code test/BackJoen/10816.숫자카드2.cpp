//숫자카드2
//https://www.acmicpc.net/problem/10816
#include <iostream>
#include <unordered_map>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int N, M;
    unordered_map<int, int> map;

    cin >> N;
    int input;
    for (int i = 0; i < N; i++) {
        cin >> input;
        map[input]++;
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> input;

        cout << map[input] << " ";
    }

}