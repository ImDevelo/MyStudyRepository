//프린터 큐
//https://www.acmicpc.net/problem/1966
#include<iostream>
#include<utility>
#include<queue>
#include<algorithm>
using namespace std;

int algorigum() {
    int N, M; //번째, 
    queue<pair<int, int>> printer;
    vector<int> v;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        printer.push({ i, temp });
        v.push_back(temp);
    }
    sort(v.begin(), v.end()); //중요도 정렬

    int counting = 0;
    while (true)
    {
        pair<int, int> front_paper = printer.front();
        
        if (v.back() == front_paper.second) { //중요도가 같은지 판별, 같다면 출력
            counting++;
            printer.pop();
            v.pop_back();
            if (front_paper.first == M) {
                //만약 출력 종이가 우리가 찾는 종이라면
                return counting;
            }
        }
        else {
            //중요도 우선이 아니라면 뒤로 백
            printer.pop();
            printer.push(front_paper);
        }
    }
    return -1;
}

void MySolution() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cout << algorigum() << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();
}