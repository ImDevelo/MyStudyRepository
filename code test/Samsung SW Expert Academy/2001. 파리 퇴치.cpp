#include<iostream>
#include <vector>

using namespace std;


// 누적합 배열을 만드는 함수
vector<vector<int>> createPrefixSum(const vector<vector<int>>& flies, int N) {
    vector<vector<int>> prefixSum(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            prefixSum[i][j] = flies[i - 1][j - 1] 
                            + prefixSum[i - 1][j] 
                            + prefixSum[i][j - 1] 
                            - prefixSum[i - 1][j - 1];
        }
    }
    return prefixSum;
}

// 최대 파리 개수를 계산하는 함수
int getMaxFlies(const vector<vector<int>>& prefixSum, int N, int M) {
    int maxFlies = 0;
    for (int i = M; i <= N; ++i) {
        for (int j = M; j <= N; ++j) {
            int currentSum = prefixSum[i][j]
                           - prefixSum[i - M][j]
                           - prefixSum[i][j - M]
                           + prefixSum[i - M][j - M];
            maxFlies = max(maxFlies, currentSum);
        }
    }
    return maxFlies;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int N, M;
		cin >> N >> M;
		vector<vector<int>> vec(N, vector<int> (N));

		for(int i=0; i < N; i++){
			for(int j = 0; j < N; j++){
				cin >> vec[i][j];
			}
		}

		vector<vector<int>> prefixSum = createPrefixSum(vec, N);
		int result = getMaxFlies(prefixSum, N, M);


        cout << "#" << test_case << " " << result << "\n";
	}
	return 0;
}