//https://www.acmicpc.net/problem/1110
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int N;
    cin >> N;
    int num = N;
    int count = 0;
    do
    {
        int f = num / 10;
        int s = num % 10;
        int sum = f + s;

        num = (s * 10 + sum % 10);
        //cout << num << " ";
        count++;
    } while (!(N == num));

    cout << count;
}