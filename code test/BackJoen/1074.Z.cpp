//https://www.acmicpc.net/problem/1074
#include <iostream>
using namespace std;

#define ll long long

ll grid(int step, int r, int c) {
	if (step == 0) {
		return 0;
	}
	int p = 1 << (step - 1);
	ll value = grid(step - 1, r % p, c % p);

	value += (1 << ((step - 1) * 2 + 1)) * (r / p);
	value += (1 << ((step - 1) * 2)) * (c / p);

	return value;
}

int main() {
	int N, x, y;
	cin >> N >> x >> y;
	cout << grid(N, x, y);
	return 0;
}