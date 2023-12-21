//달팽이는 올라가고 싶다
//https://www.acmicpc.net/problem/2869
#include<iostream>
using namespace std;
#define MAX 0

void MySolution(){
    int A,B,V;
    cin >> A >> B >> V;
    V -= A;
    A -= B;
    if(V % A != 0){
        V /= A;
        V += 1;
    }else{
        V /= A;
    }
    cout << V+1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    MySolution();
}