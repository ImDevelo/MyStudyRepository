// 회의실 배정
//https://www.acmicpc.net/problem/1931
#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;
#define MAX 100000

void MySolution(){
    int N;
    pair<int,int> arr[MAX];
    int counting = 0;
    
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i].second >> arr[i].first;
    }
    sort(&arr[0], &arr[N]);//정렬-회의 종료시간 우선
    
    int index = 0;
    int time = 0; //현제시간
    while (index < N)
    {
        int start = arr[index].second;
        int end = arr[index].first;

        if(start >= time){ //현제시간 이후에 회의 시작
            time = end;//회의 종료(현제시간 업데이트)
            counting++;
        }
        index++;
    }
    cout << counting;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    MySolution();
}