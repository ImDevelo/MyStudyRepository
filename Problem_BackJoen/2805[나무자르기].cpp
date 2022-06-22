//나무 자르기
//https://www.acmicpc.net/problem/2805
#include<iostream>
using namespace std;
#define MAX 1000000

int tree[MAX];

void MySolution(){
    int N;  //전체 나무갯수
    long M; //필요한 길이
    int highest = 0;
    cin >> N >> M;

    for(int i=0,temp; i<N; i++){
        cin >> temp;
        tree[i] = temp;
        if(temp > highest){
            highest = temp;
        }
    }
    int start = 0;
    int end = highest;
    int ans = 0;
    while (start <= end)
    {
        int mid = (start + end) / 2; 
        long miter = 0;
        for(int i=0; i<N; i++){
            if(tree[i] > mid){
                miter += (tree[i] - mid);
            }
        }
        if(miter >= M){
            ans = mid;
            start = mid + 1;
        }else{
            end = mid-1;  
        }
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    MySolution();
}