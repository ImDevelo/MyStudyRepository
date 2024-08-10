//
//https://www.acmicpc.net/problem/

#include <iostream>
#include <vector>
using namespace std;

void MySolution(){
    int N, M;
    cin >> N >> M;

    vector<int> prefixSum(N+1);
    prefixSum[0] = 0;

    int input;
    for(int i = 1; i <= N; i++){
        cin >> input;
        prefixSum[i] = prefixSum[i-1] + input;
    }

    int s, e;
    for(int i = 0; i< M; i++){
        cin >> s >> e;

        cout << prefixSum[e] - prefixSum[s-1] << "\n"; 
    }

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    MySolution();
}