//단어정렬
//https://www.acmicpc.net/problem/1181
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

bool compare(const string s1, const string s2) {
    
    if (s1.length() < s2.length()) {
       return true;
    }
    else if (s1.length() == s2.length() && s1.compare(s2) < 0) {
        return true;
    }
    return false;
}

void MySolution() {
    int N;
    cin >> N;
    string* s = new string[N];
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }

    sort(&s[0], &s[N], compare);

    cout << s[0] << "\n";
    for (int i = 1; i < N; i++) {
        if (!(s[i] == s[i - 1])) {
           cout << s[i] << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();

}