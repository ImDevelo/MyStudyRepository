//https://www.acmicpc.net/problem/2461
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> arr(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    int high_num = 0, high_class = 0; // 최대 값, 최대값인 class
    int low_num, low_class; // 최소값, 최소값인 class
    for (int i = 0; i < N; i++) {
        sort(arr[i].begin(), arr[i].end()); //정렬
        if (high_num < arr[i][0]) { // 최대값 갱신
            high_num = arr[i][0];
            high_class = i;
        }
    }

    vector<int> pos(N, 0); // 선택한 사람 번호
    int min_gap = high_num;

    while (true)
    {
        low_num = high_num;
        low_class = 0;
        for (int i = 0; i < N; i++) {
            while (pos[i] + 1 < M && arr[i][pos[i] + 1] < high_num){ // 전체 최대값보다 크진 않은 각 클래스 최대값으로 계산
                pos[i]++;
            }
            int num = arr[i][pos[i]];
            if (num < low_num) { // 최소값 찾기
                low_num = num;
                low_class = i;
            }
        }

        min_gap = min(min_gap, high_num - low_num); // 최대값과 최소값 차이 갱신
        
        if (pos[low_class] + 1 < M) {
            high_num = arr[low_class][++pos[low_class]]; // 최대값 갱신
        }
        else { // 한 클래스가 마지막까지 갔다면 종료
            break;
        }
        
    }

    cout << min_gap;

    return 0;
}
