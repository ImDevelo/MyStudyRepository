//1,2,3더하기
//https://www.acmicpc.net/problem/9095
#include<iostream>
using namespace std;

int N, S, pos;

void SumOneTwoThree(int sum){
    if(sum == S){
        pos++;
        return;
    }else if(sum < S){
        for(int i=1; i<=3; i++){
            SumOneTwoThree(sum + i);
        }
    }
}

void MySolution(){
    cin >> N;
    for(int i=0; i<N;i++){
        cin >> S;
        pos = 0;
        SumOneTwoThree(0);
        cout << pos << " ";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    MySolution();

}