#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int test_case;
	int T = 10;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N;
        cin >> N;

        priority_queue<pair<int, int>> q;
        vector<int> city(N);

        int input;
        for(int i=0 ; i < N; i++) {
            cin >> input;
            city[i] = input;
            if(input != 0){
                q.push({input, i});
            }
        }

        int result = 0;

        while (!q.empty())
        {
            int b_hight = q.top().first;
            int b_index = q.top().second;
            q.pop();

            int near_building = max({ city[b_index - 2], city[b_index - 1], city[b_index + 1], city[b_index + 2]});
            int good_view = b_hight - near_building;

            if(good_view > 0){
                result += good_view;
            }
            //cout << "Check : " << b_index << " Near" << near_building << "-" << good_view << "\n";
        }

        cout << "#" << test_case << " " << result << "\n";
	}
	return 0;
}