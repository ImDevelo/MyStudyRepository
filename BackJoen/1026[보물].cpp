// 보물
// https://www.acmicpc.net/problem/1026
#include<iostream>
#include<algorithm>
using namespace std;

#define MAX 51
int N;
int arr1[MAX];
int arr2[MAX];


void MySolution(){
    cin >> N;

    for(int i=0; i<N ; i++ ){
        cin >> arr1[i];
    }
    sort(&arr1[0],&arr1[N]);

    for(int i=0; i<N ; i++ ){
        cin >> arr2[i];
    }
    sort(&arr2[0],&arr2[N]);

    int answer = 0;
    for(int i=0; i<N ; i++){
        int temp;
        temp = arr1[i]*arr2[N-i-1];
        answer += temp;
    }
    cout << answer << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();
}