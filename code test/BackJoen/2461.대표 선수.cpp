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

    int high_num = 0, high_class = 0; // �ִ� ��, �ִ밪�� class
    int low_num, low_class; // �ּҰ�, �ּҰ��� class
    for (int i = 0; i < N; i++) {
        sort(arr[i].begin(), arr[i].end()); //����
        if (high_num < arr[i][0]) { // �ִ밪 ����
            high_num = arr[i][0];
            high_class = i;
        }
    }

    vector<int> pos(N, 0); // ������ ��� ��ȣ
    int min_gap = high_num;

    while (true)
    {
        low_num = high_num;
        low_class = 0;
        for (int i = 0; i < N; i++) {
            while (pos[i] + 1 < M && arr[i][pos[i] + 1] < high_num){ // ��ü �ִ밪���� ũ�� ���� �� Ŭ���� �ִ밪���� ���
                pos[i]++;
            }
            int num = arr[i][pos[i]];
            if (num < low_num) { // �ּҰ� ã��
                low_num = num;
                low_class = i;
            }
        }

        min_gap = min(min_gap, high_num - low_num); // �ִ밪�� �ּҰ� ���� ����
        
        if (pos[low_class] + 1 < M) {
            high_num = arr[low_class][++pos[low_class]]; // �ִ밪 ����
        }
        else { // �� Ŭ������ ���������� ���ٸ� ����
            break;
        }
        
    }

    cout << min_gap;

    return 0;
}
