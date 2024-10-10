//https://www.acmicpc.net/problem/2096
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> dp_min(N), dp_max(N);

    for (int i = 0, in; i < N; i++) {
        cin >> in;
        dp_min[i] = dp_max[i] = in;
    }
    
    vector<int> dp_min_temp(N), dp_max_temp(N);
    for (int n = 1; n < N; n++) {
        
        
        for (int i = 0, in; i < N; i++) {
            cin >> in;
            
            if (i == 0) {
                dp_min_temp[i] = min({ dp_min[0], dp_min[1] }) + in;
                dp_max_temp[i] = max({ dp_max[0], dp_max[1] }) + in;
            }
            else if (i == N - 1) {
                dp_min_temp[i] = min({ dp_min[N - 2], dp_min[N - 1] }) + in;
                dp_max_temp[i] = max({ dp_max[N - 2], dp_max[N - 1] }) + in;
            }
            else {
                dp_min_temp[i] = min({ dp_min[i - 1], dp_min[i],dp_min[i + 1] }) + in;
                dp_max_temp[i] = max({ dp_max[i - 1], dp_max[i],dp_max[i + 1] }) + in;
            }

        }
        dp_min = dp_min_temp;
        dp_max = dp_max_temp;
    }

    cout << *max_element(dp_max.begin(), dp_max.end()) << endl;
    cout << *min_element(dp_min.begin(), dp_min.end()) << endl;

    return 0;
}
