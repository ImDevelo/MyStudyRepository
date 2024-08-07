//등수 구하기
//https://www.acmicpc.net/problem/1205
#include <iostream>
#include <vector>
using namespace std;
int main() {
	int N, P, score;
	int high = 0, same = 0;

	cin >> N >> score >> P;
	
	for (int i = 0, input; i < N; i++) {
		cin >> input;
		if (input > score) high++;
		else if (input == score) same++;
	}
	if (high + same < P) cout << high + 1;
	else cout << -1;
}