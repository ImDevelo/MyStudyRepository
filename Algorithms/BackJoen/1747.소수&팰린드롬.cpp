//소수&팰린드롬
//https://www.acmicpc.net/problem/1747
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) 
        return false;
    if (num <= 3) 
        return true; 
    if (num % 2 == 0 || num % 3 == 0) 
        return false;

    for (int i = 5; i <= sqrt(num); i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) 
            return false;
    }
    return true;
}

bool isPalindrome(int number) {  
    string str = to_string(number);
    int len = str.size();

    for (int k = 0; k < len / 2; k++) {
        if (str[k] != str[len - k - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = N; ; i++) {
        if (isPrime(i) && isPalindrome(i)) {
            cout << i;
            break;
        }
    }

    return 0;
}
