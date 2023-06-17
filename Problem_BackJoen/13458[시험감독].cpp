//시험 감독
//https://www.acmicpc.net/problem/13458
#include<iostream>
using namespace std;
#define MAX 1000000

int examination[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int N;
    int supervisor, subervisor;
    long long supervisor_count = 0;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> examination[i];
    }

    cin >> supervisor >> subervisor;
    for (int i = 0; i < N; i++) {
        int temp = examination[i] - supervisor;
        supervisor_count++;
        if (temp > 0) {
            int under = temp % subervisor;
            int upper = temp / subervisor;
            supervisor_count += (long long)upper;
            if (under > 0) {
                supervisor_count++;
            }
        }
    }
    cout << supervisor_count;
}