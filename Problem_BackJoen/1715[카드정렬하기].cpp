//카드 정렬하기
//https://www.acmicpc.net/problem/
#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 100000

void MySolution(){
    int N;
    int arr[MAX];

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    sort(&arr[0], &arr[N]);

    int ans1 = 0, ans2 = 0;

    ans1 += (arr[0]*(N-1) + arr[1]*(N-1));
    for(int i=2 ;i<N; i++){
        ans1 += (arr[i] * (N-i));
    }
    ans2 = 1000000;
    
    for(int i=0; i<N; i++){
        ans2 += (arr[i]*(N-1));
    }
    
    cout << min(ans1, ans2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    MySolution();
}