//https://www.acmicpc.net/problem/1541
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<string> splitString(const string& str, char delimiter) {
    vector<string> tokens;
    stringstream ss(str);
    string token;

    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

int sum(const string str) {
    vector<string> strs = splitString(str, '+');
    int sum = 0;
    for (string s : strs) {
        sum += stoi(s);
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    string str;
    cin >> str;

    vector<string> split;
    split = splitString(str, '-');

    int result = sum(split[0]);
    for (int i = 1; i < split.size(); i++) {
        result -= sum(split[i]);
    }

    cout << result;
}