//ZOAC 4
//https://www.acmicpc.net/problem/23971
#include<iostream>
#include <cmath>
using namespace std;
#define MAX 0

void MySolution(){
    double H, W, N, M;
    cin >> H >> W >> N >> M;

    int R = std::ceil(W / (M+1.0));
    int C =  std::ceil(H / (N+1.0));

    cout << R*C << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    MySolution();
}