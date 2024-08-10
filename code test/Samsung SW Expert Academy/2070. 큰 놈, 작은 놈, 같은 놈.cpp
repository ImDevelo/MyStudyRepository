#include<iostream>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int a, b;
        cin >> a >> b;

        int comp = a - b;
        if(comp == 0){
            cout << "#" << test_case << " " << "=";
        }
        else if(comp < 0){
            cout << "#" << test_case << " " << "<";
        }
        else{
            cout << "#" << test_case << " " << ">";
        }
        
	}
	return 0;
}