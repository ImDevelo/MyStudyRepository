#pragma once
#include <iostream>
#include <algorithm>
#include<vector>
#include<string>

using namespace std;


bool DFS(const string result, string& value) {

	if (value.length() >= result.length()) {
		if (value == result) {
			return true;
		}
		return false;
	}

	string str = value;

	// 规过 1 利侩
	str += "X";
	if (DFS(result, str)) { return true; }
	str.pop_back();

	// 规过 2 利侩
	reverse(str.begin(), str.end());
	str += "Y";
	if (DFS(result, str)) { return true; }
	str.pop_back();
	reverse(str.begin(), str.end());
	return false;
}


void MySolution() {

	string S, E;
	cin >> S >> E;

	if (DFS(E, S)) {
		cout << "Yes" << "\n";
	}
	else {
		cout << "No" << "\n";
	}


}