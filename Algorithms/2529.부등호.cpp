//부등호
//https://www.acmicpc.net/problem/2529
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void dfs(string inequality, int pos, vector<bool>& check, string sum , string& high , string& low) {

	if (pos > inequality.size()) {
		high = max(high, sum);
		low = min(low, sum);
		return;
	}

	for (int i = 0; i < 10; i++) {

		if (check[i] == true) {
			continue;
		}
		else if (pos > 0 && ((inequality[pos-1] == '>' && sum[pos - 1] - '0' < i) || (inequality[pos - 1] == '<' && sum[pos - 1] - '0' > i) )) {
			continue;
		}
		check[i] = true;
		sum += to_string(i);
		dfs(inequality, pos + 1, check, sum, high, low);
		check[i] = false;
		sum.pop_back();
		
	}
}

int main() {
	int K;
	string str, max = "0", min = "9999999999";
	vector<bool> check(10, false);

	cin >> K;

	char input;
	for (int i = 0; i < K; i++) {
		cin >> input;
		str += input;
	}
	dfs(str, 0 , check, "", max, min);
	cout << max << " " << min;
}