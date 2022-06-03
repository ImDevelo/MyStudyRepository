//소수의 연속합
//https://www.acmicpc.net/problem/1644
#include<iostream>
#include<vector>
using namespace std;

#define MAX 4000002
vector<int> pv;
bool primary[MAX];

void setPrimary(int max){

    primary[0] = true;
    primary[1] = true;
    for(int i=2; i<=max; i++){
        if(primary[i] == false){
            pv.push_back(i);
            int index = i*2;
            while (index <= max)
            {
                primary[index] = true;
                index += i;
            }
        }
    }
}

bool divid(int i, int N){
    int sum = 0;
    for(int j=i; j<pv.size(); j++){
        sum += pv.at(j);
        if(sum == N){
            return true;
        }else if(sum > N){
            return false;
        }
    }
    return false;
}

void MySolution(){
    int N;
    cin >> N;
    setPrimary(N);
    
    int couting = 0;
    for(int i=0; i<pv.size() ; i++){
        
        if(divid(i,N)){
            couting++;
        }
    }
    cout << couting;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();
}