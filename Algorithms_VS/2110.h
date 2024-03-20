#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void MySolution() {
	int N, C;
	cin >> N >> C;
	vector<long> house(N);

	for (int i = 0; i < house.size(); i++){
		cin >> house[i];
	}
	sort(house.begin(), house.end());

	int maxDistance = (house[N - 1] - house[0]);
	int high = maxDistance / (C - 1);
	int low = 1;
    int ans = 0;

	while (low <= high)
	{
		int mid = (high + low) / 2;
		int value = 0;

		int count = 0;
		int distance = 0;
		
		cout << "low " << low << "~ mid " << mid << " ~ high" << high << endl;
		
		int point = house[0] + mid;

		for (int i = 0; i < N - 1; i++) {
			if (house[i] >= point) {

				point = house[i] + mid;

				
			}
		}

		/*
		for (int i = 0; i < (N-1); i++) {
			distance += house[i + 1] - house[i];
			
			if (distance >= mid) {
				value += distance;
				distance = 0;
				count++;
				cout << distance << " " << value << " ";
			}
		}
		*/

		cout << "sum " << value << endl;

		if (count > C-2) {
			low = mid + 1;
			ans = mid;
		}
		else {
			high = mid - 1;
		}
		
	}
	std::cout << ans;
}


