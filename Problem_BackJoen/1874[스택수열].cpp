//스택 수열
//https://www.acmicpc.net/problem/1874
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

#define MAX 100000

void MySolution(){
    int N;
    int arr[MAX];
    stack<int> s;
    vector<char> v;
    cin >> N;

    for(int i =0; i<N;i++){
        cin >> arr[i];
    }

    int counting = 0;
    for(int i =1; i<=N; i++){
        s.push(i);
        v.push_back('+');
        while (counting < N && !s.empty() && arr[counting] == s.top())
        {
            v.push_back('-');
            s.pop();
            counting++;
        }
    }

    if(s.empty()){
        vector<char>::iterator iter;
        for(iter = v.begin(); iter!= v.end(); iter++){
             cout << *iter << " ";
        }
    }else{
        cout << "NO";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();
}