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
        int N;
        priority_queue<int> low;
        priority_queue<int, vector<int>, greater<int>> high;

        cin >> N;

        for(int i = 0; i< N; i++){
            int input;
            cin >> input;

            if(low.empty() ){
                low.push(input);
            }
            else if(low.top() < input){
                if(low.size() <= high.size()){
                    low.push(high.top());
                    high.pop();
                }
                high.push(input);
            }
            else{
                if(low.size() > high.size()){
                    high.push(low.top());
                    low.pop();
                }
                low.push(input);
            }
        }
        

        cout << "#" << test_case << " " << low.top() << "\n";
	}
	return 0;
}