//연료채우기
//https://www.acmicpc.net/problem/1826
#include<iostream>
#include<utility>
using namespace std;
#define MAX 10000

int N, L, P;
int gasStation[MAX][2];
int bestAns = 0;

void Town(int miter, int count, int fuel, int start){
    if(miter+fuel >= L){
        if(bestAns == 0 || bestAns > count){
            bestAns = count;
        }
        return;
    }
    for(int i = start; i<N; i++){
        int m = gasStation[i][0] - miter;
        int f = gasStation[i][1];
        
        if(fuel-m >= 0 ){
            Town(gasStation[i][0],count+1,fuel+f-m,i+1);
        }
    }
}

//
/*







*/

void MySolution(){
    cin >> N;
    for(int i = 0; i<N; i++){
        cin >> gasStation[i][0] >> gasStation[i][1];
    }
    cin >> L >> P;

    Town(0,0,P,0);

    cout << bestAns;
}





int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    MySolution();
}

