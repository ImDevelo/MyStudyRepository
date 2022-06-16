//
//https://www.acmicpc.net/problem/
#include<iostream>
using namespace std;
#define MAX 1000

int N;
int arr[MAX];
int best[MAX];


void MySolution(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
        best[i] = 1;
    }

    for(int i=0; i<N; i++){
        if(best[i] == 1){
            int start = arr[i];

            for(int j=i+1; j<N; j++){
                if(arr[j] >= start){
                    if(arr[j] > arr[j-1]){

                    }else{

                    }
                }
            }
        }
    }

    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    MySolution();
}