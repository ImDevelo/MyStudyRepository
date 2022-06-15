//연속합
//https://www.acmicpc.net/problem/
#include<iostream>
using namespace std;
#define MAX 100001

void MySolution(){
    int N, best = 0;
    int arr[MAX];
    int sumarr[MAX];
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
        sumarr[i] = 0;
    }
    best = arr[0];
    int temp = arr[0];
    for(int i=1; i<N; i++){
        for(int j=i; j<N;j++){
            temp += arr[j];
            if(temp > sumarr[j]){
                sumarr[j] = temp;
                if(temp > best){
                    best = temp;
                }
            }
            cout << sumarr[j] << " ";
        }
        temp = 0;
        cout << endl;
    }
    cout << best;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    MySolution();
}