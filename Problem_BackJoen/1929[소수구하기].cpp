//소수 구하기
//https://www.acmicpc.net/problem/1929
#include<iostream>
using namespace std;

int primary(int n){
    if(n == 1){
        return -1;
    }else{
        for(int i=2; i<n;i++){
            if( n % i == 0 ){
                return -1;
            }
        }
    }
    return n;
}


void MySolution(){
    int N , M;
    cin >> N >> M; 
    for(int i=N, temp; i<=M;i++){
        temp = primary(i);
        if( temp != -1)
            cout << temp << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();

}