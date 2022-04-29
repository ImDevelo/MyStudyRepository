#include<iostream>
using namespace std;
#define Max 1

int N, K;

void MySolution(){
    cin >> N >> K;
    unsigned long long value = N;
    
    for(int i = 2; i <= K; i++){
        value *= (N - i + 1 );
        value /= i;
    }

    value = value % 10007;

    cout << value << endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();

}