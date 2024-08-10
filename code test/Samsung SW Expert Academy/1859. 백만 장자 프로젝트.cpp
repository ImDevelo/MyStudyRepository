#include<iostream>
#include<queue>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
	int T;


	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        vector<int> v;
        priority_queue<pair<int,int>> pq;

        int N;
        cin >> N;
        for(int i=0; i<N; i++){
            int input;
            cin >> input;
            v.push_back(input);
            pq.push({input, i});
        }

        
        long long pay = 0;
        int days = 0;
        while (days < N)
        {
            pair<int, int> top = pq.top();
            int target_pay = top.first;
            int target_days = top.second;
            pq.pop();
            
            if(days > target_days){
                continue;
            }
            
            for(int i=days; i<target_days; i++){
                if((target_pay - v.at(i)) >= 0){
                    pay += (target_pay - v.at(i));
                }
            }

            days = target_days + 1;
        }
        
        cout << "#" << test_case << " " << pay << "\n";
	}
	return 0;
}