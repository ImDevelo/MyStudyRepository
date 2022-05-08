//[가운데를 말해요]
//https://www.acmicpc.net/problem/1655

#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    priority_queue<int, vector<int>, greater<int>> greaterIndex; //중간값보다 큰것
    priority_queue<int, vector<int>, less<int>> lessIndex; //중간값보다 작은것
    cin >> N;
    int index;
    for(int i=0; i<N; i++){
        cin >> index;
        lessIndex.push(index);
        if(!greaterIndex.empty() && lessIndex.size() == greaterIndex.size()+1){
            if(greaterIndex.top() < lessIndex.top()){ // 교체
                int temp = greaterIndex.top();
                greaterIndex.pop();
                greaterIndex.push(lessIndex.top());
                lessIndex.pop();
                lessIndex.push(temp);
            }
        }else if(lessIndex.size() == greaterIndex.size()+2){
                greaterIndex.push(lessIndex.top());
                lessIndex.pop();
        }
        cout << lessIndex.top() << " ";
    }
}