//연산자 끼워넣기
//https://www.acmicpc.net/problem/14888
#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 12
#define PLUS 0
#define MINUS 1
#define MULTI 2
#define DIVIS 3

int N;
int arr[MAX];
int operators[4];
int minnum, maxnum;
bool first = false;

void Cululator(int n, int number){
    if(n == N){
        if(!first){
            minnum = number;    maxnum = number;
            first = true;
        }else{
            maxnum = max(maxnum, number);
            minnum = min(minnum, number);
        }
        return;
    }
    for(int i=0; i<4; i++){
        int result = number;
        if(operators[i] != 0){
            switch (i){
            case PLUS:  result += arr[n]; break;
            case MINUS: result -= arr[n]; break;
            case MULTI: result *= arr[n]; break;
            case DIVIS: result /= arr[n]; break;
            default:    break;
            }
            
            operators[i] -= 1;
            Cululator(n+1, result);
            operators[i] += 1;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    for(int i=0; i<4;i++){
        cin >> operators[i];
    }
    Cululator(1, arr[0]);
    cout << maxnum << " " << minnum << "\n";
}