#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;

    int teams = min(a / 2, b) - max(0, (a + b - min(a / 2, b) * 3 + c - 2) / 3);

    cout << max(0, teams);
    return 0;
}