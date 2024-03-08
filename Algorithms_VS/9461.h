#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void TestCase() {
	int N;
	cin >> N;
	
	vector<long long> v(5);
	
	v[0] = 1; v[1] = 1; v[2] = 1; v[3] = 2; v[4] = 2;

	for (int i = 5; i < N; i++)
	{
		v.push_back(v[i - 1] + v[i - 5]);
	}

	cout << v[N - 1] << "\n";

}

void MySolution() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		TestCase();
	}
}