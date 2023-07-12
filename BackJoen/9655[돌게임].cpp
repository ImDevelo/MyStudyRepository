//돌게임
//https://www.acmicpc.net/problem/9655
#include <iostream>
using namespace std;
#define MAX 0

void MySolution(){
    int N;
    cin >> N;

    if(N%2){
        cout << "SK";
    }else{
        cout << "CY";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    MySolution();
}