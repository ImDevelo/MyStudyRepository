//동전0
//https://www.acmicpc.net/problem/11047
#include<iostream>
using namespace std;
#define MAX 10

void MySolution(){
    int N;
    long long K;
    long long m[MAX];
    int counting = 0;
    cin >> N >> K;
    for(int i=0; i<N;i++){
        cin >> m[i];
    }
    int coin = N-1;
    while (K != 0)
    {
        if(K < m[coin]){
            coin--;
            continue;
        }else{
            counting += K / m[coin];
            K %= m[coin];
            
        }
    }
    cout << counting;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    MySolution();
}