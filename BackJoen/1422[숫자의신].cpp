//숫자의 신
//https://www.acmicpc.net/problem/1422
#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;

struct cmp {
bool operator()(string a, string b) {
    if(a.compare(b)==0){
        return false;
    }
    int le = min(a.size(), b.size());
    int i;
    for(i=0; i<le; i++){
        if(a.at(i) == b.at(i)){
            continue;
        }else if(a.at(i) > b.at(i)){
            return false;
        }else{
            return true;
        }
    }
    if(a.size() > b.size()){
        if(a.at(i) == b.at(0)){
            if(a.at(0) > b.at(i-1)){
                return false;
            }else{
                return true;
            }
        }
        else if(a.at(i) > b.at(0)){
            return false;
        }else{
            return true;
        }
    }else{
        if(a.at(0) == b.at(i)){
            if(a.at(i-1) > b.at(0)){
                return false;
            }else{
                return true;
            }
        }
        else if(a.at(0) > b.at(i)){
            return false;
        }else{
            return true;
        }
    }
    return false;
}
};



void MySolution(){
    int N, K;
    //가장 큰 수 등록
    long bestNumber = 0;
    
    priority_queue<string,vector<string>,cmp> q;
    cin >> K >> N;
    long t;
    for(int i=0,t;i<K;i++){
        cin >> t;
        if(bestNumber < t){
            bestNumber = t;
        }
        q.push(to_string(t));
    }
    string bt = to_string(bestNumber);
    while (!q.empty())
    {
        string s = q.top();
        cout << s;
        if(bt.compare(s) == 0){
            for(int i=0; i<N-K; i++){
                
                cout << s;
            }
        }
        q.pop();
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    MySolution();
}