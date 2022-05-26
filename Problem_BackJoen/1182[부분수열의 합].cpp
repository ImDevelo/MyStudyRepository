//부분수열의 합
//https://www.acmicpc.net/problem/1182
#include<iostream>
#include<vector>
using namespace std;

#define MAX 20

void MySolution(){
    int N , S;
    vector<int> mins;
    vector<int> plus;
    cin >> N >> S;

    int temp;
    for(int i=0; i<N;i++){
        cin >> temp;
        if(temp > 0){
            plus.push_back(temp);
        }else{
            mins.push_back(temp);
        }
    }
    while (true)
    {
    }
    
    

    //조합의 방법






}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();

}