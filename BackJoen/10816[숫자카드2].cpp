//숫자카드2
//https://www.acmicpc.net/problem/10816
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int N, M;
    multiset<int> s;

    cin >> N;
    for(int i=0, t; i<N;i++){
        cin >> t;
        s.insert(t);
    }

    cin >> M;
    multiset<int>::iterator iter;
    for(int i=0, x; i<M; i++){
        cin >> x;
    }
}