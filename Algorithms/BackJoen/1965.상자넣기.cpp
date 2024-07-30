//상자 넣기
//https://www.acmicpc.net/problem/1965
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 0


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int N;
    int good = 1;
    cin >> N;
    vector<int> box(N);
    vector<int> dp(N);

    for(int i=0; i<N; i++){
        cin >> box[i];
    }

    dp[0] = 1;
    for(int i=1; i<N; i++){
        int local_max = 1;

        for(int j = 0; j < i; j++){
            if(box[i] > box[j]){
                local_max = max(local_max, dp[j] + 1);
            }
        }
        
        dp[i] = local_max;
        good = max(good, dp[i]);
    }

    cout << good << "\n";

}