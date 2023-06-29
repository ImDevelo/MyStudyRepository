//랜선자르기
//https://www.acmicpc.net/problem/1654
#include<iostream>
using namespace std;
#define MAX 10000

void MySolution(){
    int N, K; 
    long max = 0;
    long len[MAX];
    cin >> N >> K;

    for(int i=0,temp; i<N; i++){
        cin >> temp;
        len[i] = temp;
        if(max < temp){
            max = temp;
        }
    }

    long start = 1, end = max;
    long ans = 0;
    while (start <= end)
    {
        long mid = (start + end) / 2;
        long count = 0;

        for(int i=0; i<N ;i++){
            count += len[i] / mid;
        }
        if(count >= K){
            start = mid + 1;
            ans = mid;
        }else{
            end = mid - 1;
        }
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    MySolution();
}