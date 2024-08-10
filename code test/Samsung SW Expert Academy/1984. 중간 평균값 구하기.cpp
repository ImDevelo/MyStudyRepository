#include<iostream>
#include<vector>
#include<climits>
#include<cmath>

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
        int min = INT_MAX, max = 0;
        long long sum = 0;


        for(int i=0; i<10; i++){
            int input;
            cin >> input;
            sum += input;

            if(input < min){
                min = input;
            }
            if(input > max){
                max = input;
            }
        }

        sum -= min; sum -= max;


        int result = round(sum / 8.0);

        cout << "#" << test_case << " " << result << "\n";
	}
	return 0;
}