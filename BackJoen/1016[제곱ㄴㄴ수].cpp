//제곱ㄴㄴ수
//https://www.acmicpc.net/problem/1016
#include<iostream>
#include<vector>
using namespace std;
#define MAX 100000

bool primary[MAX];
long long minN, maxN;
vector<long long> v;

void setPrimary(int max){
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
    cin >> minN >> maxN;
    setPrimary(maxN);
    bool arr* = new bool[maxN-minN];
    int n;
    int sum = 0;
    for(int i=2; i<=MAX; i++){
        if(primary[i] == false){
            n = i*i;
            if(n > maxN){
                break;
            }
            int index = n;
            while (index <= max)
            {
                primary[index] = true;
                index += i;
            }
        }
            


        }
    }

    cout << sum << endl;
        
    cout << (maxN - minN + 1) - sum;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    MySolution();
}