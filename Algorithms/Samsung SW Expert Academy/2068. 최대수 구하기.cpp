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
        priority_queue<int> pq;
        int num[10];

        for(int i=0, input; i<10; i++){
            cin >> input;
            pq.push(input);
        }

        cout << "#" << test_case << " " << pq.top() << "\n";
	}
	return 0;
}