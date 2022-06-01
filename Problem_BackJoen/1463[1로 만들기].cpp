//1로 만들기
//https://www.acmicpc.net/problem/1463
/*
X가 3으로 나누어 떨어지면, 3으로 나눈다.
X가 2로 나누어 떨어지면, 2로 나눈다.
1을 뺀다.
*/
#include<iostream>
using namespace std;

int counting = 0;

void DFS(int n, int cnt){
    if(n == 1){
        if(counting == 0 || counting > cnt){
            counting = cnt;
        }
    }else{

        if(n%3 == 0){
            DFS(n/3,cnt+1);
        }else if(n%2 == 0){
            DFS(n-1,cnt+1);
            DFS(n/2,cnt+1);
        }else{
            DFS(n-1,cnt+1);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin >> N;

    DFS(N,0);
    cout << counting;
}