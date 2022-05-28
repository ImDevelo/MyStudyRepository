//숨바꼭질
//https://www.acmicpc.net/problem/1697
#include<iostream>
#include<queue>
using namespace std;

#define MAX 100010

int N, K;
int lower;
int arr[MAX];
bool check[MAX];


void HideAndSeek(){
    queue<int> q;
    q.push(N);
    check[N] = true;

    while (!q.empty())
    {
        int point = q.front();
        q.pop();


        if(point*2 < MAX){
            
        }



    }
    



}


void MySolution(){
    cin >> N >> K;
    cout << "!" << endl;

    HideAndSeek(N,0);
    cout << arr[K];
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();

}