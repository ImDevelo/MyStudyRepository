//예산
//https://www.acmicpc.net/problem/2512
#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 100000

void MySolution(){
    int N;
    long M; //총 예산
    int arr[MAX];

    cin >> N;
    for(int i=0; i<N;i++){
        cin >> arr[i];
    }
    cin >> M;

    int left = 1;
    int right = *max_element(arr, arr+N);
    int ans = 0;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        long count = 0;

        for(int i=0; i<N; i++){
            int s = arr[i];
            if(arr[i] > mid){
                s = mid;
            }
            count += s;
        }

        if(count <= M){
            left = mid + 1;
            ans = mid;
        }else{
            right = mid -1;
        }
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    MySolution();
}