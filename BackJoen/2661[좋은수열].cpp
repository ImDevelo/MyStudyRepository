//좋은 수열
//https://www.acmicpc.net/problem/2661
#include<iostream>
#include<vector>
using namespace std;
#define MAX 81

int arr[MAX];
int N;
bool findAns = false;

bool isGood(int len){
    bool isDif;
    if(len == 0){
        return true;
    }
    for(int i=1; i<=(len+1)/2; i++){
        isDif = true;
        if(arr[len] == arr[len-i]){
            isDif = false;
            for(int j=1; j<i; j++){
                if(arr[len-j] != arr[len-i-j])
                    isDif = true;
            }
            if(isDif == false) 
                return false;
        }
    }
    return isDif;
}

void GoodSequence(int len){
    if(len == N){
        for(int i=0; i<N; i++)
            cout << arr[i];
        findAns = true;
        
        return;
    }
    for(int i=1; i<=3; i++){
        arr[len] = i;
        if(isGood(len) && !findAns){
            GoodSequence(len+1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    GoodSequence(0);
}