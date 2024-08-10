//나머지
//https://www.acmicpc.net/problem/10430
#include<iostream>
using namespace std;
#define MAX 0

void MySolution(){
    int A, B, C;
    cin >> A >> B >> C;

    int Ans1 = (A+B)%C;
    int Ans2 = ((A%C) + (B%C))%C;
    int Ans3 = (A*B)%C;
    int Ans4 = ((A%C)*(B%C))%C;

    cout << Ans1 << " " << Ans2 << " " << Ans3 << " " << Ans4 << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    MySolution();
}