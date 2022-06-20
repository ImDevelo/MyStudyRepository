//과자 나눠주기
//https://www.acmicpc.net/problem/16401
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//입력
	int M, N;
	vector<int> L;
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		int l;
		cin >> l;
		L.push_back(l);
	}

	//이분탐색, 이진탐색
	int left = 1, right = *max_element(L.begin(), L.end());
	//left: 가장 작은 수, right: 가장 큰 수
	int snack = 0;
	while (left <= right) {
        
		int mid = (left + right) / 2; //중앙값
		int count = 0;
		cout << snack << " " << mid << " | ";
        for (int i = 0; i < N; i++) {
			count += L[i] / mid; //mid 과자 길이로 나눠줄수 있는 양
		}
        
		if (count >= M) { //과자 나눠줄수 있을 때
			left = mid + 1;
			snack = mid;
		}
		else if (count < M) { //과자 나눠줄수 없을 때
			right = mid - 1;
		}
	}
    cout << endl;
	cout << snack << "\n";

	return 0;
}