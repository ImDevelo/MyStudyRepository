//요세푸스
//https://www.acmicpc.net/problem/1158
#include<iostream>
#include<list>
#include<vector>
using namespace std;

void MySolution() {
    int N, K;
    list<int> l;
    vector<int> v;
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        l.push_back(i);
    }

    list<int>::iterator itr = l.begin();
    int r = 1;//순번
    while (!l.empty())
    {
        for (int i = 0; i < K-1; i++) {
            itr++;
            if (itr == l.end()) {
                itr = l.begin();
            }
            
        }
        v.push_back(*itr);
        itr = l.erase(itr);
        if (itr == l.end()) {
            itr = l.begin();
        }
    }
    
    vector<int>::iterator itrv;
    cout << "<" << v[0];
    for (itrv = ++v.begin(); itrv != v.end(); itrv++) {
        cout << ", " << *itrv;
    }
    cout << ">";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();

}