//https://www.acmicpc.net/problem/24416
#include<stdio.h>
using namespace std;


int f[41] = { 0,1,1 };
int cnt1 = 0;
int cnt2 = 0;

int fib(int n) {
    if (n == 1 || n == 2) {
        cnt1++;
        return 1;
    }
    else return (fib(n - 1) + fib(n - 2));
}

int fibo(int n) {
    for (int i = 3; i <= n; i++) {
        cnt2++;
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}

int main() {
    int n;
    scanf("%d", &n);
    fib(n);
    fibo(n);
    printf("%d %d", cnt1, cnt2);
    return 0;
}