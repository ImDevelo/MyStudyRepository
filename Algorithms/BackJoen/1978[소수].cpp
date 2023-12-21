//소수
//https://www.acmicpc.net/problem/1978
#include<iostream>
using namespace std;

int primary(int n){
    if(n == 1){
        return 0;
    }
    for(int i=2; i<n;i++){
        if( n % i == 0 ){
            return 0;
        }
    }
    return 1;
}


void MySolution(){
    int N , sum = 0;
    cin >> N; 
    for(int i=0, temp; i<N;i++){
        cin >> temp;
        sum += primary(temp);  
    }
    cout << sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();

}