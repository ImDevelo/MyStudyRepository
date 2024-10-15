//https://www.acmicpc.net/problem/2668
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> arr(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    vector<bool> term(N + 1, false), visited(N + 1, false);
    vector<int> ans;
    for (int i = 1; i <= N; i++) {
        if (visited[i] == true) {
            continue;
        }
        // DFS 텀 구하기
        vector<int> pos;
        int index = i, cir_num = 0;
        pos.push_back(index);

        while (true)
        {
            int next_index = arr[index];
            visited[index] = true;
            if (term[next_index] == true) {
                // 다음 숫자가 텀인 경우
                break;
            }
            else if (visited[next_index] == true) {
                // 순환되는 번호를 찾은 경우
                cir_num = next_index;
                break;
            }
            else {
                pos.push_back(next_index);
                index = next_index;
            }
        }

        bool isTerm = false;
        for (int p : pos) {
            
            if (p == cir_num) {
                isTerm = true;
            }
            term[p] = isTerm;
            if (term[p]) {
                ans.push_back(p);
            }
        }

    }

    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for (int n : ans) {
        cout << n << " ";
    }

}