//https://www.acmicpc.net/problem/10986
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	unordered_map<long, long> map;
	long long pix_sum = 0;
	for (int i = 1, input; i <= N; i++) {
		cin >> input;
		pix_sum = pix_sum + input;
		map[pix_sum % M]++;
	}

	long ans = map[0];
	for (auto v : map) {
		long value = v.second;
		ans += (value * (value - 1)) / 2;
	}
	cout << ans;

}
