#include<iostream>
#include<string>

using namespace std;

int main(int argc, char** argv)
{
    string str, result;
    cin >> str;

    for(char c : str){
        char chr = c;
        if(chr >= 'a' && chr <= 'z' ) {
            chr = chr - 32;
        }
        result += chr;
    }

    cout << result << endl;

	return 0;
}