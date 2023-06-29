//주유소
//https://www.acmicpc.net/problem/13305
#include<iostream>
using namespace std;

void MySolution() {
    int N;
    long long* distance, * fuel;
    long long bestPrice = 0;
    cin >> N;

    distance = new long long[N - 1];
    fuel = new long long[N];
    for (int i = 0; i < N - 1; i++) {
        cin >> distance[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> fuel[i];
    }

    long long minPrice = fuel[0];
    for (int i = 0; i < N - 1; i++) {
        if (fuel[i] < minPrice) {
            minPrice = fuel[i];
        }
        bestPrice += (minPrice * distance[i]);
    }

    cout << bestPrice;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    MySolution();
}