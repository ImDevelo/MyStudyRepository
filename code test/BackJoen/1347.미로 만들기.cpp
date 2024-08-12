//https://www.acmicpc.net/problem/1347
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    
    int N;
    int min_r = 0, min_c = 0, max_r = 0, max_c = 0;
    
    cin >> N;
    string command;
    cin >> command;

    set<pair<int, int>> index;
    int dr[4] = { 1,0,-1,0 };
    int dc[4] = { 0,-1, 0 , 1 };
    int d = 0, r = 0, c = 0;

    index.insert({ 0,0 });
    
    for (int i = 0; i < N; i++) {
        char com = command[i];

        if (com == 'F') {
            r += dr[d];
            c += dc[d];
            min_r = min(r, min_r);
            min_c = min(c, min_c);
            max_r = max(r, max_r);
            max_c = max(c, max_c);
            index.insert({ r,c });
            
        }
        else if(com == 'R') {
            d = (d + 1) % 4;
        }
        else if (com == 'L') {
            d = (4 + d - 1) % 4;
        }
    }

    set<pair<int,int>>::iterator it = index.begin();

    for (int i = min_r; i <= max_r; i++) {
        for (int j = min_c; j <= max_c; j++) {
            if (it != index.end() && (*it).first == i && (*it).second == j) {
                cout << ".";
                ++it;
            }
            else {
                cout << "#";
            }
        }
        cout << "\n";
    }
}