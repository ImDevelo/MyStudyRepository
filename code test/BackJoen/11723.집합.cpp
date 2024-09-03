//https://www.acmicpc.net/problem/11723
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	vector<bool> arr(21, false);
	while (N--)
	{
		string str;
		int num;
		cin >> str;

		if (str != "empty" && str != "all") {
			cin >> num;
			if (str == "add") {
				arr[num] = true;
			}
			else if (str == "remove") {
				arr[num] = false;
			}
			else if (str == "check") {
				cout << arr[num] << "\n";
			}
			else if (str == "toggle") {
				arr[num] = !arr[num];
			}
		}
		else {
			if (str == "all") {
				for (int i = 1; i <= 20; i++) {
					arr[i] = true;
				}
			}
			else {
				for (int i = 1; i <= 20; i++) {
					arr[i] = false;
				}
			}
		}
	}





}
