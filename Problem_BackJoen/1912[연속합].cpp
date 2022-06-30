//연속합
//https://www.acmicpc.net/problem/
#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 100001

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    
    int N, best;
    int arr[MAX];

    cin >> N;
    for(int i=0, n; i<N; i++){
        cin >> n;
        arr[i] = n;
    }

    best = arr[0];
    for(int i=1; i<N; i++){
        arr[i] = max(arr[i], arr[i] + arr[i-1]);
        best = max(arr[i], best);
    }

    cout << best;
}