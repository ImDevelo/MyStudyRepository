//최대공약수와 최소공배수
//https://www.acmicpc.net/problem/2609
#include<iostream>
using namespace std;

int commonMeasure(int a, int b){
    int x; 
    if(a<b){x=a;}else{x=b;}
    for(int i=x; i>=2 ;i--){
        if(a%i == 0 && b%i == 0 ){
            return i;
        }
    }
    return -1;
}

void MySolution(){
    int N, M;
    cin >> N >> M;
    int a = N, b = M;

    cout << commonMeasure(a,b);


    a = N; b = M;
    while (true)
    {
         if(a == b){
            cout << a << " ";
            break;
        }else if(a < b){
            a += N;
        }else{
            b += M;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();

}