//피고나치 함수
//https://www.acmicpc.net/problem/1003
#include<iostream>
using namespace std;
#define MAX 41

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int Zero[MAX], One[MAX];
    int N, T;
    cin >> T;   

    Zero[0] = 1; Zero[1] = 0;
    One[0] = 0; One[1] = 1;
    for(int i=2; i<=40; i++){
        Zero[i] = Zero[i-1] + Zero[i-2];
        One[i] = One[i-1] + One[i-2];
    }   

    for(int i=0; i<T; i++){
        cin >> N;
        cout << Zero[N] << " " << One[N] << "\n";
    }
}
