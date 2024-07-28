#include<iostream>
#include <vector>

using namespace std;
 
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int N = 0;
        long long ans = 0;
        
        cin >> N;

        vector<int> days(N, 0);
        
        for(int i = 0; i < N; i++){
            cin >> days[i];
        }

        int price = 0;
        for(int j = N-1; j >= 0; j--){
            if(price < days[j]){
                price = days[j];
            }else if(price > days[j]){
                ans += price - days[j];
            }
        }

        cout << "#" << test_case << " " << ans << "\n";
    }
    return 0;
}