//피고나치 함수
//https://www.acmicpc.net/problem/1003
#include<iostream>
using namespace std;


int fibonacci(int n) {
    if (n == 0) {
        printf("0");
        return 0;
    } else if (n == 1) {
        printf("1");
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

void MySolution(){
    cout << fibonacci(10) << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();

}
