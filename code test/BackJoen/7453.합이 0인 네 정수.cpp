//https://www.acmicpc.net/problem/7453
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    vector<long> a(N), b(N), c(N), d(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    vector<long> sum1, sum2;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum1.push_back(a[i] + b[j]);
            sum2.push_back(-(c[i] + d[j]));
        }
    }

    sort(sum1.begin(), sum1.end());
    sort(sum2.begin(), sum2.end());

    long long result = 0;
    for (int i = 0; i < sum1.size(); i++) {
        auto lower = lower_bound(sum2.begin(), sum2.end(), sum1[i]);
        auto upper = upper_bound(sum2.begin(), sum2.end(), sum1[i]);
        result += upper - lower;
    }

    cout << result << "\n";
    return 0;
}
