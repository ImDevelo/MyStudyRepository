//부분수열
//https://www.acmicpc.net/problem/1182
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, s, pos;
vector<int>num;

void solution(vector<int>visit, int now, int start, int sum) {
	
	if (now > 1 && sum == s) {
		pos++;
	}

	for (int i = start;i < num.size();i++) {
		if (!visit[i]) {
			visit[i] = true;
			sum += num[i];
			solution(visit, now + 1, i + 1, sum);
			visit[i] = false;
			sum -= num[i];
		}
	}
}

int main() {
	cin >> n >> s;
	
	for (int i = 0,t=0;i < n;i++) {
		cin >> t;
		num.push_back(t);
	}
	sort(num.begin(), num.end());
	solution(vector<int>(n+1,0),1,0,0);
	
	cout << pos;


}