//https://www.acmicpc.net/problem/4779
#include <iostream>
#include <math.h>
using namespace std;

void lineSplit(string& str, int start, int length) {

    if (length == 1) {
        return;
    }

    int len = length / 3;

    for (int i = start + len; i < start + len * 2; i++) {
        str[i] = ' ';
    }

    lineSplit(str, start, len);
    lineSplit(str, start + len * 2, len);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (true)
    {
    int N;

    cin >> N;

    if (cin.eof() == true)
    {
        break;
    }

    string str = "-";
    for (int i = 0; i < N; i++) {
        string s;
        for (int i = 0; i < 3; i++) {
            s += str;
        }
        str = s;
    }

    lineSplit(str, 0, pow(3,N));

    cout << str << "\n";
    }


}