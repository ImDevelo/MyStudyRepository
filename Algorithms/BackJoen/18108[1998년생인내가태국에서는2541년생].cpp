//1998년생인 내가 태국에서는 2541년생?!
//https://www.acmicpc.net/problem/18108
#include<iostream>
using namespace std;
void MySolution(){
    int year;
    cin >> year;
    cout << (year - 543); 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    MySolution();
}