//숨바꼭질
//https://www.acmicpc.net/problem/1697
#include<iostream>
#include<queue>
using namespace std;

#define MAX 100002
int N, K;
int bestAns = 0;
int arr[MAX];

void HideAndSeek(int start, int target){
    queue<int> q;
    int bestCnt = 0;
    q.push(start);
    arr[start] = 0;

    while (!q.empty())
    {
        int num[3] = {q.front()*2, q.front()+1, q.front()-1};
        int cnt = arr[q.front()]; // 횟수
        q.pop();
        if(bestAns != 0 && cnt > bestAns){
            continue;
        }

        for(int i=0; i<3 ;i++){
            int n = num[i];
            if(n >= 0 && n < MAX){
                if(arr[n] == -1 || arr[n] > cnt){
                    q.push(n);
                    arr[n] = cnt + 1;
                    if(n == K && (bestAns == 0 || cnt + 1 < bestAns)){
                        bestAns = cnt + 1;
                        return;
                    }
                }
            }
        }
    }
}

void MySolution(){
    for(int i=0; i<MAX; i++){
        arr[i] = -1;
    }
    cin >> N >> K;
    HideAndSeek(N,K);
    cout << bestAns;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();
}