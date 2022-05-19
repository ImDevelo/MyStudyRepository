// 괄호
// https://www.acmicpc.net/problem/9012
#include<iostream>
#include<string>
using namespace std;

bool temp(string* s){
    bool isVPS = false;
    int open = 0;
    int close = 0;
    for(int j=0; j<s->length();j++){
        if(s->at(j)=='('){
            open++;
        }
        else if(s->at(j)==')'){
            close++;
        }

        if(open == close){
            isVPS = true;
        }else if(open > close){
            isVPS = false;
        }else if(open < close){
            return false;
        }
    }
    return isVPS;
}


void MySolution(){
    int N;
    cin >> N;
    string* s = new string[N];
    for(int i = 0; i < N; i++){
        cin >> s[i];
    }

    bool isVPS = false;    
    for(int i =0; i<N; i++){
        if(temp(&s[i]))
            cout << "YES\n";
        else
            cout << "NO\n";   
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();

}