//최소공배수
//https://www.acmicpc.net/problem/1934
#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 0

int Euclidean(int a, int b){
    int m = max(a,b);
    int n = min(a,b);
    while ((m %= n) != 0){
        swap(n,m);
    }
    return n;
}

void MySolution(){
    int T, a, b;
    cin >> T;

    for(int i=0; i<T; i++){
        cin >> a >> b;
        cout << (a * b / Euclidean(a,b)) << " ";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    MySolution();
}