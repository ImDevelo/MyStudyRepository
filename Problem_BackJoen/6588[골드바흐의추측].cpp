//골드바흐의 추측
//https://www.acmicpc.net/problem/6588
#include<iostream>
using namespace std;
#define MAX 1000002
bool primary[MAX];

void setPrimary(){
    primary[0] = true;
    primary[1] = true;
    for(int i=2; i<=MAX; i++){
        
        if(primary[i] == false){
            int index = i*2;
            while (index <= MAX)
            {
                primary[index] = true;
                index += i;
            }
        }
    }
    primary[2] = true;
}

int Goldbach(int n){
    for(int i=3; i<n ; i++){
        if(primary[i] == false && primary[n-i] == false){
            return i;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    setPrimary();
    int N, ans;
    while (cin >> N, N != 0)
    {
        ans = Goldbach(N);
        cout << N << " = " << ans << " + " << (N-ans) << "\n";
    }
}