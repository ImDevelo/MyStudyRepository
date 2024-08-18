//https://www.acmicpc.net/problem/15649
#include <iostream>
using namespace std;

bool check[8];
int str[8];

void DFS(int N, int M, int count) {

    if (count == M) {
        for (int i = 0; i < M; i++) {
            cout << str[i] + 1  << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++) {
        
        if (check[i] != true) {
            check[i] = true;
            str[count] = i;
            DFS(N, M, count + 1);
            check[i] = false;
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    DFS(N, M, 0);

}