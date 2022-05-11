//수찾기
//https://www.acmicpc.net/problem/1920
#include<iostream>
using namespace std;

void MySolution(){
    int N, M;
    cin >> N;
    int* arr = new int[N];
    for(int i=0; i<N;i++){
        cin >> arr[i];
    }

    cin >> M;
    int* arr2 = new int[M];
    for(int i=0; i<M;i++){
        cin >> arr2[i];
    }


    for(int i=0; i<M;i++){
        int exist = 0;
        for(int j=0; j<N;j++){
            if(arr2[i] == arr[j]){
                exist = 1;
                break;
            }
        }
        cout << exist << " ";
    }


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();

}