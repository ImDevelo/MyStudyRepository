//십자카드 문제
//https://www.acmicpc.net/problem/2659
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void MySolution() {
	int number_index[4];

	for (int i = 0; i < 4; i++)
	{
		cin >> number_index[i];
	}

	int cross_number = 9999;

	for (int i = 0; i < 4; i++)
	{
		int number = 1000 * number_index[i % 4] + 100 * number_index[(i+1) % 4] +  10 * number_index[(i + 2) % 4] + number_index[(i + 3) % 4];

		cross_number = min(number, cross_number);
	}
	//cout << cross_number << endl;
	int count = 0;
	bool find = false;
	for (int i = 1; i < 10 && !find; i++)
	{
		for (int j = 1; j < 10 && !find; j++)
		{
			if (i >  j) {
				continue;
			}
			for (int k = 1; k < 10 && !find; k++)
			{
				if (i > k) {
					continue;
				}

				for (int l = 1; l < 10 && !find; l++)
				{
					if (i > l) {
						continue;
					}
					int number = 1000 * i + 100 * j + 10 * k + l;
					
					if (i == l && ( l < k || l < j )) {
						continue;
					}
					else if (i == k && (l < j)) {
						continue;
					}
					count++;
					if (number >= cross_number) {
						find = true;
						break;
					}
				}
			}
		}
	}
	cout << count;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();

}