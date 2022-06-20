//공유기 설치
//https://www.acmicpc.net/problem/2110
#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 200000



void MySolution(){
    int N, C;
    int arr[MAX];
    int d[MAX];
    cin >> N >> C;

    for(int i=0; i< N ;i++){
        cin >> arr[i];
    }
    sort(&arr[0], &arr[N]);

    //공유기 설치
    // 1 5 10 15 20 28 4  8 총 필요한 거리수는 c-1개
    // 각 거리수는 5 5 5 5 8 이 3숫자를 적당히 합해서 (인접한 숫자끼리) 균등하게 만들어라
    // 3 4 5 8 7 4 6 3 공유기 3개 총 2개의 합
    // 12 15 13 그럼 12 이 3개의 숫자의 합은 40

    // 3 7 12 (20/8) 15 (19/4) 10 13

    // 1 100 10000  





}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    MySolution();
}