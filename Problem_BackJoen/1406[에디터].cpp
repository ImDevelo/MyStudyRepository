//에디터
//https://www.acmicpc.net/problem/1406
#include<iostream>
#include<string>
using namespace std;

void MySolution(){
    int N, M, cuser;
    string s;
    cin >> s >> M;
    cuser = s.length();
    for(int i=0; i<M;i++){
        char c;
        cin >> c;
        if(c == 'L'){
            if(cuser > 0)
                cuser--;
        }else if(c == 'D'){
            if(cuser < s.length())
                cuser++;
        }else if(c == 'B'){
            if(cuser > 0){
                s.erase(cuser-1,1);
                cuser--;
            }
        }else if(c == 'P'){
            string temp;
            cin >> temp;
            if(cuser < s.length()){
                s.insert(cuser,temp);
            }else if(cuser >= s.length()){
                s.append(temp);
            }
            cuser++;
        }
    }
    cout << s;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();

}