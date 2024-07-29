#include<iostream>
#include<string>
#include<vector>

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
		int  N;
		cin >> N;
		vector<vector<int>> vec(N, vector<int> (N, 0));

		vec[0][0] = 1;

		for(int i=1; i<N; i++){
			for(int j=0; j<i+1; j++){
				if(j == 0 || j == i){
					vec[i][j] = 1;
				}else{
					vec[i][j] = vec[i-1][j-1] + vec[i-1][j];
				}
			}
		}

		// 출력 
        cout << "#" << test_case << "\n";
		for(int i=0; i<N; i++){
			for(int j=0; j<i+1; j++){
				cout << vec[i][j] << " ";
			}
			cout << "\n";
		}


	}
	return 0;
}