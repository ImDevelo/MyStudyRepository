//좋은 수열
//https://www.acmicpc.net/problem/2661
#include<iostream>
#include<vector>
using namespace std;
vector<int> v;
int N;
bool finded = false;

int GoodNum(int n, int len){
    int seq = (len+1)/2;
    bool isGood = true;
    for(int i=1; i<=seq; i++){
        if(n == v[len - i]){
            if(i == 1){
                isGood = false;
                break;
            }
            for(int j=1; j<=(i-1); j++){
                if(v[len-j] == v[len-i-j]){
                    isGood = false;
                    continue;
                }else{
                    isGood = true;
                    break;
                }
            }
        }
    }
    if(isGood){
        return n;
    }else{
        return 0;
    }
    
}

bool GoodSequence(int len) {
    if(len == N){
        vector<int>::iterator itr;
        for(itr=v.begin(); itr!=v.end(); itr++){
            cout << *itr;
        }
        return true;
    }
    for(int i=1; i<=3; i++){
        int n = GoodNum(i,len);
        if(n){
            v.push_back(n);
            if(GoodSequence(len+1)){
                return true;
            }
            v.pop_back();
        }
    }
    return false;
}

void MySolution() {
    cin >> N;
    v.push_back(1);
    GoodSequence(1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();
}