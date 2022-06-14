//연속합
//https://www.acmicpc.net/problem/
#include<iostream>
using namespace std;
#define MAX 0


void MySolution(){
    bool inputPlus = false; // 양수값이 들어온 적이 있는지 판단 
    bool inputSum = false; // 합이 결정됬는지 판단 이유: *1
    int bestSum = 0;
    int tempSum = 0;
    int N;

    cin >> N;
    for(int i=0, input; i<N; i++){
        cin >> input;

        if(input >= 0){ //양수
            inputPlus = true;
            bestSum = true;
            tempSum += input;
            if(i == (N-1)){
                if(bestSum < tempSum){
                    bestSum = tempSum;
                }
            }
        }else{//음수
            if(inputPlus == false){ // 한번도 양수가 들어온적 없는경우
                if(input < 0){//입력값 음수
                    if(inputSum == false || bestSum < input){ // *1
                        bestSum = input;
                        inputSum = true;
                    }
                }
            }
        }
    }
    cout << bestSum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    MySolution();
}