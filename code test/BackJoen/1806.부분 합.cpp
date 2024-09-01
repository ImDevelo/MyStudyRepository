//https://www.acmicpc.net/problem/1806
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, S;
	cin >> N >> S;

	vector<int> pfx_sum(N+1);
	
	pfx_sum[0] = 0;
	for (int i = 1, input; i <= N; i++) {
		cin >> input;
		pfx_sum[i] = pfx_sum[i - 1] + input;
	}

	int point_back = 1, point_front = 0;
	int length = 0;

	while ( point_back <= N )
	{
		int sum = pfx_sum[point_back] - pfx_sum[point_front];

		if (sum >= S) {
			if (length == 0 || length > point_back - point_front) {
				//cout << point_front << "~" << point_back << "=" << sum << "\n";
				length = point_back - point_front;
			}
			point_front++;
		}
		else {
			point_back++;
		}
	}

	cout << length;
}
