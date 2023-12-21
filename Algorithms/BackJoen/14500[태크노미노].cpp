//테크로미노
//https://www.acmicpc.net/problem/14500
//무엇이 문제였는가?
//1. 정리가 제대로 되지 않음 -> 실수 유발
//2.태캐 제대로 정리 못함
#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 504


int arr[MAX][MAX] = {0};
int R, C;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
        }
    }

    int best = 0;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            //일자
            best = max(best, arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 3][j]);
            best = max(best, arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i][j + 3]);

            //사각형
            best = max(best, arr[i][j] + arr[i + 1][j] + arr[i][j + 1] + arr[i + 1][j + 1]);

            //번개
            best = max(best, arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j + 2]);
            best = max(best, arr[i + 1][j] + arr[i + 1][j + 1] + arr[i][j + 1] + arr[i][j + 2]);
            best = max(best, arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j + 1]);
            best = max(best, arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j] + arr[i + 2][j]);

            // 낫
            best = max(best, arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 2][j + 1]);
            best = max(best, arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i][j + 1]);
            best = max(best, arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j + 1]);
            best = max(best, arr[i + 2][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j + 1]);
            best = max(best, arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 2]);
            best = max(best, arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j]);
            best = max(best, arr[i][j] + arr[i + 1][j] + arr[i+1][j + 1] + arr[i+ 1][j + 2]);
            best = max(best, arr[i][j + 2] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2]);

            // 오
            best = max(best, arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 1][j + 1]);
            best = max(best, arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j + 1] + arr[i + 1][j]);
            best = max(best, arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1]);
            best = max(best, arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2] + arr[i][j + 1]);
        }
    }
    cout << best;
}