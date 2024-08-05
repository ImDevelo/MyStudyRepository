//어항정리
//https://www.acmicpc.net/problem/23291
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int target;
int N, K;
int arr[100];
int temp[100][100];

void fold_90() {
	int fold_col = N;
	int fold_X;

	int fold_size = 0;
	
	while (true) {



		
	}
}

void flod_180() {




}

void distribution() {
	
	queue<pair<int, int>> q;
	vector<vector<bool>> check(N, vector<bool>(N));

	q.push({ 0, N - 1 });

	while (q.empty())
	{


	}
}


void arrangement() {
	//#1 가장 적은 위치에 한마이응 넣는다.
	vector<int> low_pos;
	int low_value = 10001;
	for (int i = 0; i < N; i++) {
		if (arr[i] < low_value) {
			low_pos.clear();
			low_pos.push_back(i);
			arr[i] = low_value;
		}
		else if (arr[i] == low_value) {
			low_pos.push_back(i);
		}
	}

	//#2 만약 여러개면 전부다 넣는다.
	for (int i = 0; i < low_pos.size(); i++) {
		int index = low_pos[i];
		arr[index]++;
	}

	//#3 가장 왼쪽 어항을 오른쪽 위에 놀린다.

	
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int count = 0;
	while ( target >= K )
	{
		arrangement();
		count++;
	}

	cout << count;

	return 0;
}


