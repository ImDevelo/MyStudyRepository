//이항계수 3
//https://www.acmicpc.net/problem/11401
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007LL;
int N, K;
//mod MOD 거듭제곱(분할 정복)
ll pow(ll a, ll b) {
	if (b == 0) return 1;
	if (b % 2 > 0) return (pow(a, b - 1) * a) % MOD;
	ll half = pow(a, b / 2) % MOD;
	return (half * half) % MOD;
}

/* 식 정리
A = n!	B = k!(n-k)!	P=1000000007
A*B^-1 % P
A*B^(2-p) % P = (A%P)*(B^(p-2)%P)%P >>패르마 소정리에 의해
(1) A % P
(2) B^(p-2) % P
(3) D % P   >> (D = (1)*(2))
*/

void AtherSolution(){
    cin >> N >> K;
	ll A = 1, B = 1; //A = n!, B = k!(n-k)!
	// (1)
	for (ll i = 1; i <= N; i++) {
		A *= i;
		A %= MOD;
	}
	//(2)
	for (ll i = 1; i <= K; i++) {
		B *= i;
		B %= MOD;
	}
	for (ll i = 1; i <= N - K; i++) {
		B *= i;
		B %= MOD;
	}
	ll B2 = pow(B, MOD-2); // B2 = B^(MOD-2)
	ll ans = A * B2;
	ans %= MOD;
	cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    AtherSolution();
}
