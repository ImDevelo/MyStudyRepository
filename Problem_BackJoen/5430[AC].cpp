// AC <실패>
// https://www.acmicpc.net/problem/5430
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

void algorisum() {
    int N;
    string p, num;
    vector<string> l;
    cin >> p >> N;

    if (N > 0) {
        cin >> num;
        num.erase(0, 1); num.erase(num.length() - 1, 1); //대괄호 제거

        int start = 0;
        int d = num.find(',');

        while (d != -1)
        {
            l.push_back(num.substr(start, d - start));
            start = d + 1;
            d = num.find(',', start);
        }
        l.push_back(num.substr(start, d - start));
    }else{
        cin >> num;
        num = "";
    }


    for (int i = 0; i < p.length(); i++) {
        if (p.at(i) == 'R') { //반대로
            reverse(l.begin(), l.end());
        }
        else if (p.at(i) == 'D') { //삭제
            if (l.empty()) {
                cout << "error\n";
                return;
            }
            l.erase(l.begin());
        }
    }

    cout << "[";
    if(!l.empty()){
        for (int i = 0; i < l.size() - 1; i++) {
        cout << l[i] << ",";
        }
        cout << l.back();
    }
    cout << "]\n";
}

void MySolution() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        algorisum();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();
}