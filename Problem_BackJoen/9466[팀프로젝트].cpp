//텀 프로젝트
//https://www.acmicpc.net/problem/9466
#include<iostream>
#include<stack>
using namespace std;
#define MAX 100001

int T, N;
int arr[MAX];
bool Tum[MAX];

void findTum(int start) {
    stack<int> s;
    int index = start;
    for (int i = 1; i <= N; i++) {
        s.push(index);
        index = arr[index];
        if (index == start) {
            int top;
            while (!s.empty())
            {
                top = s.top();
                Tum[top] = true;
                s.pop();
            }
            return;
        }
        else if (Tum[index] == true) {
            Tum[start] = false;
            return;
        }
    }
    Tum[start] = false;
    return;
}

void TumProject() {
    cin >> N;
    for (int i = 1, temp; i <= N; i++) {
        cin >> temp;
        arr[i] = temp;
        Tum[i] = false;
        if (temp == i) { // 자기자신이 팀인 경우
            Tum[i] = true;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (Tum[i] != true) {
            findTum(i);
        }
    }

    int noTum = 0;
    for (int i = 1; i <= N; i++) {

        if (Tum[i] == false) {
            noTum++;
        }
    }
    cout << noTum << endl;
}

void MySolution() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        TumProject();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    MySolution();
}