//피고나치 수 3
//https://www.acmicpc.net/problem/2749

#include<iostream>
using namespace std;

unsigned long long N;
unsigned long arr[3];

void MySolution(){
    cin >> N;
    if(N > 2){
        arr[0] = 1; arr[1] = 1;
        for(int i = 2; i<N;i++){
            arr[2] = (arr[0] + arr[1]);
            arr[0] = arr[1];
            arr[1] = arr[2];
        }
        cout << arr[2];
    }else if(N==0){
        cout << 0;
    }else{
        cout << 1;
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();

}