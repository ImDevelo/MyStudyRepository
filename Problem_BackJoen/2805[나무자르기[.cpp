//나무 자르기
//https://www.acmicpc.net/problem/2805
#include<iostream>
using namespace std;
#define MAX 1000000

void MySolution(){
    int N;  //전체 나무갯수
    long M; //필요한 길이
    long tree[MAX];
    cin >> N >> M;
    int highest = 0;
    for(int i=0,temp; i<N; i++){
        cin >> temp;
        tree[i] = temp;
        if(temp > highest){
            highest = temp;
        }
    }
    int start = 0;
    int end = highest;
    int h, cut = 0;
    while (true)
    {
        if(start > end){
            cout << h;
            break;
        }
        h = (start + end) / 2;
        for(int i=0; i<N; i++){
            if(tree[i] > h){
                cut += (tree[i] - h);
            }
        }
        if(cut < M){
            end = h-1;
        }else{
            start = h+1;
        }

        cut = 0;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    MySolution();
}