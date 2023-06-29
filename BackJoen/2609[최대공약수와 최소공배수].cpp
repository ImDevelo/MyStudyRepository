//최대공약수와 최소공배수
//https://www.acmicpc.net/problem/2609
#include<iostream>
using namespace std;

int Euclidean(int a, int b){
    int m = max(a,b);
    int n = min(a,b);
    while ((m %= n) != 0){
        swap(n,m);
    }
    return n;
}

void MySolution(){
    int N, M;
    cin >> N >> M;
    int E = Euclidean(N,M);

    cout << E << " " << (N*M/E);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();

}