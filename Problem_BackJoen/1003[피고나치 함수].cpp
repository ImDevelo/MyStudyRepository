//피고나치 함수
//https://www.acmicpc.net/problem/1003
#include<iostream>
using namespace std;
#define MAX 41

int arr[MAX];
int Zero = 0, One = 0;



int fibonacci(int n) {
    if(){
        
    }



    if (n == 0) {
        printf("0");
        Zero++;
        return 0;
    } else if (n == 1) {
        printf("1");
        One++;
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

void MySolution(){
    cout << fibonacci(22) << endl;
    cout << Zero << " " << One << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();

}
