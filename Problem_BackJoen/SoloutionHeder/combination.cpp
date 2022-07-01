//
//https://www.acmicpc.net/problem/
#include<iostream>
using namespace std;

#define MAX 14
int num[MAX];
int arr[MAX];
int N;

void combination(int count, int start, int end){
    if(count == end){
        for(int i=0;i<end;i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
    }else{
        for(int i=start; i<end;i++){
            arr[count] = num[i];
            algorisum(count + 1, i+1, end);
        }
    }
    return;
}

void MySolution(){
    while (true)
    {
        cin >> N;
        if(N == 0)
            return;
        for(int i=0; i<N;i++){
            cin >> num[i];
        }
        algorisum(0,0,N);
        cout << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();
}