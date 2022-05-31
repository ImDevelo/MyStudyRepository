//최대공약수와 최소공배수
//https://www.acmicpc.net/problem/2609
#include<iostream>
using namespace std;

int commonMeasure(int n){
    for(int i=2; i<=n ;i++){
        if(n%i == 0){
            return (n/i);
        }
    }
    return -1;
}

void MySolution(){
    int N, M;
    cin >> N >> M;
    
    int a = N, b = M;
    
    cout << a << b;

    /*
    while (true)
    {
        cout << a << b;
        if(a == b){
            cout << a << " ";
            break;
        }else if(a > b){
            a = commonMeasure(a);
        }else{
            b = commonMeasure(b);
        }
        
    }
    */
   for(int i=0; i<20;i++){
               
        if(a == b){
            cout << a << " ";
            break;
        }else if(a > b){
            a = commonMeasure(a);
        }else{
            b = commonMeasure(b);
        }
        cout << a << b << " ";
   }

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