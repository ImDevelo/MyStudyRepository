// A+B-4
// https://www.acmicpc.net/problem/10951

#include<iostream>
using namespace std;
int main(){
    int a, b;
    while(true){
        cin >> a >> b;
        if (cin.eof())
			break;
        cout << a + b << endl;

    }
    
    return 0;
}