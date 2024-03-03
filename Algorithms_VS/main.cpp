#include<iostream>
#include"10816_2.h"


#include <iostream>
#include <vector>
#include <set>
using namespace std;


void MySolution() {
	int M, N;
	multiset<int> number;
	vector<int> search;


	cin >> N;
	for (int i = 0, temp; i < N; i++) {
		cin >> temp;
		number.insert(temp);
	}

	cin >> M;
	for (int j = 0, temp; j < M; j++) {
		cin >> temp;
		search.push_back(temp);
		cout << number.count(temp) << " ";
	}
}




int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);  std::cout.tie(NULL);

	MySolution();

}