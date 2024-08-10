//삼각형과 세 변
//https://www.acmicpc.net/problem/5073
#include <algorithm>
#include <iostream>
using namespace std;

void MySolution() {
    int a[3];

    while (true) {
        cin >> a[0] >> a[1] >> a[2];
        if (!a[0] && !a[1] && !a[2])
            break;

        sort(a, a + 3);

        if( a[0] + a[1] <= a[2] ){
            cout << "Invalid";
        } 
        else if( a[0] == a[1] && a[1] == a[2] ){
            cout << "Equilateral";
        }
        else if( a[0] != a[1] && a[1] != a[2] && a[0] != a[2] ){
            cout << "Scalene";
        }
        else{
            cout << "Isosceles";
        }

        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();

    return 0;
}