//https://www.acmicpc.net/problem/12904
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s, t;
    cin >> s >> t;

    while ( s != t && t.size() > s.size())
    {
        if (t.back() == 'A') {
            t.pop_back();
        }
        else {
            t.pop_back();
            reverse(t.begin(), t.end());
        }
    }

    if (s == t) {
        cout << 1;
    }
    else {
        cout << 0;
    }
}
