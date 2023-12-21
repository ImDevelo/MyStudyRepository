#include<iostream>
using namespace std;
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int N = 0;
        long long ans = 0;
        
        cin >> N;
        int* days = new int[N];

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
        delete days;

        printf("#%d %d\n",test_case, ans);
    }
    return 0;
}