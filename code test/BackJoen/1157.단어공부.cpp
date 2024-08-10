//단어 공부
//https://www.acmicpc.net/problem/1157
#include<iostream>
#include<string>
#include<cctype>
#include<algorithm>
using namespace std;

void MySolution() {
    std::string input;
    int char_num[26] = {};
    int higher_char_num = 0;

    std::getline(cin, input);

    for (char c : input) {
        char n = toupper(c);
        int* target = &char_num[n - 65];
        (*target)++;
        if (*target > char_num[higher_char_num]) {
            higher_char_num = n - 65;
        }
    }

    sort(char_num, char_num+26, greater<int>());

    if (char_num[0] > char_num[1]) {
        cout << (char)(higher_char_num + 65) << endl;
    }
    else {
        cout << "?" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();
    return 0;
}