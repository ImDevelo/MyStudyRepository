//로프
//https://www.acmicpc.net/problem/2217
#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 100000

void MySolution(){
    int N;
    int arr[MAX];
    int bestWeight = 0;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    sort(&arr[0],&arr[N],greater<>());

    for(int i=0; i<N; i++){
        bestWeight = max(bestWeight, arr[i]*(i+1));
    }
    cout << bestWeight;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    MySolution();
}