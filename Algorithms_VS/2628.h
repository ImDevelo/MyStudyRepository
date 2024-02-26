#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void MySolution() {
	int N, M , C;
	vector<int> input_c, input_r;

	cin >> N >> M;
	
	cin >> C;

	input_c.push_back(0);
	input_r.push_back(0);
	for (int i = 0; i < C; i++)
	{
		int type, value;
		cin >> type >> value;

		if (type == 0) {
			input_r.push_back(value);
		}
		else {
			input_c.push_back(value);
		}
	}
	input_c.push_back(N);
	input_r.push_back(M);

	sort(input_c.begin(), input_c.end());
	sort(input_r.begin(), input_r.end());

	int max_c = 0, max_r = 0; 

	for (int i = 0; i < input_c.size() - 1; i++)
	{
		int front, end, gap;
		front = input_c.at(i);
		end = input_c.at(i+1);
		gap = end - front;
		max_c = max(max_c, gap);
	}

	for (int i = 0; i < input_r.size() - 1; i++)
	{
		int front, end, gap;
		front = input_r.at(i);
		end = input_r.at(i + 1);
		gap = end - front;
		max_r = max(max_r, gap);
	}
	int ans_size = max_c * max_r;

	cout << ans_size << endl;

}
