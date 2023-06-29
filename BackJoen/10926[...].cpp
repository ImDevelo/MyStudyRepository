#include <iostream>
#include <string>
using namespace std;

void MySolution() {
    string name;
    
    cin >> name;
    name = name + "??!";
    cout << name;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();
}