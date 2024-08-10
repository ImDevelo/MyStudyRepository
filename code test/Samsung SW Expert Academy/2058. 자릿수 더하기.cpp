#include<iostream>
#include<string>

using namespace std;

int main(int argc, char** argv)
{
    int sum = 0;
    string str;
    cin >> str;

    for(int i=0; i< str.size() ; i++){
        char c = str[i];
        int num = c - '0';
        sum += num;
    
    }

    cout << sum << "\n";

	return 0;
}