//수정렬하기
//https://www.acmicpc.net/problem/2750
#include<iostream>
#include<algorithm>
using namespace std;

void MySolution(){
    int N;    
    cin >> N;
    int* arr = new int[N];

    for(int i =0;i<N;i++){
        cin >> arr[i];
    }
    sort(&arr[0], &arr[N]);
    
    for(int i =0;i<N;i++){
        cout << arr[i] << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();

}