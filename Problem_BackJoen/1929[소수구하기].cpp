//소수 구하기
//https://www.acmicpc.net/problem/1929
#include<iostream>
using namespace std;

#define MAX 1000002
bool primary[MAX];

void setPrimary(int max){
    primary[0] = true;
    primary[1] = true;
    
    for(int i=2; i<=max; i++){
        
        if(primary[i] == false){
            int index = i*2;
            while (index <= max)
            {
                primary[index] = true;
                index += i;
            }
        }
    }
}

void MySolution(){
    int N , M;
    cin >> N >> M;
    setPrimary(M);

    for(int i=N; i<=M;i++){
        if(primary[i] == false){
            cout << i << " ";
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();

}