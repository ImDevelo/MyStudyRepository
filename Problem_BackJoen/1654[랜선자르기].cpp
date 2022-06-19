//
//https://www.acmicpc.net/problem/
#include<iostream>
using namespace std;
#define MAX 10000

void MySolution(){
    int N, K, max = 0;
    int len[MAX];
    cin >> K >> N;

    for(int i=0,temp; i<N; i++){
        cin >> temp;
        len[i] = temp;
        if(max < temp){
            max = temp;
        }
    }

    int start = 0, end = max;
    int meter = max/2;
    int count = 0;
    while (true)
    {
        



        if(){

        }else if(){

        }else{

        }
        

    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    MySolution();
}