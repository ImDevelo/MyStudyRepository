//정수 삼각형
//https://www.acmicpc.net/problem/1932
#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 500

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int N;
    int arr[MAX][MAX];

    cin >> N;

    cin >> arr[0][0];
    for(int i=1; i<N;i++){
        for(int j=0, temp; j<=i;j++){
            cin >> temp;
            arr[i][j] = temp;
            if(j == 0){
                arr[i][j] += arr[i-1][0];
            }else if(j == i){
                arr[i][j] += arr[i-1][j-1];
            }else{
                arr[i][j] += max(arr[i-1][j],arr[i-1][j-1]);
            }
        }
    }
    int best = arr[N-1][0];
    for(int i=1; i<N; i++){
        best = max(best, arr[N-1][i]);
    }
    cout << best;
}