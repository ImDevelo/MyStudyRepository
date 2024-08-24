//https://www.acmicpc.net/problem/1629
#include <iostream>
using namespace std;

long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod; 

    while (exp > 0) {

        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod; 

    }
    return result;
}

int main() {
    long long base, exp, mod;

    cin >> base >> exp >> mod;

    cout << mod_exp(base, exp, mod) << endl;

    return 0;
}
