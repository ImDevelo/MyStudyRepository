//과자 나누어주기
//https://www.acmicpc.net/problem/16401
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 1000000

void MySolution(){
	int N, M;
	vector<int> v;
	cin >> M >> N;

	for(int i=0, t; i<N; i++){
		cin >> t;
		v.push_back(t);
	}

	int start = 1;
	int end = *max_element(v.begin(), v.end());
	int ans = 0;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		int count = 0;
		for(int i=0; i<N ; i++){
			count += (v[i] / mid);
		}
		if(count >= M){//부족하다면
			start = mid + 1;
			ans = mid;
		}else{
			end = mid - 1;
		}
	}

	cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    MySolution();
}