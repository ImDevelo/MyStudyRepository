//2×n 타일링 2
//https://www.acmicpc.net/problem/11726
#include<iostream>
using namespace std;
#define MAX 1001

int N;
int arr[MAX];


void MySolution(){
    cin >> N;
    arr[0] = 1;
    arr[1] = 1;

    for(int i = 2; i <= N; i++){
        arr[i] = (arr[i-1] + (arr[i-2]*2)) % 10007;
    }
    cout << arr[N];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    MySolution();
}