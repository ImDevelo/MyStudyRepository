//가로수
//https://www.acmicpc.net/problem/2485
#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 100000

void MySolution(){
    int N;
    int U;  //가로수 거리의 최대공약수
    int ans = 0; //답 
    int arr[MAX];
    int d[MAX];

    cin >> N;
    for(int i=0; i<N;i++){
        cin >> arr[i];
    }

    d[1] = (arr[1] - arr[0]);
    U = d[1];
    for(int i=2; i<N; i++){
        d[i] = arr[i] - arr[i-1];
        U = __gcd(U,d[i]);
    }

    for(int i=1; i<N; i++){
        ans += d[i] / U - 1;
    }
    
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    MySolution();
}