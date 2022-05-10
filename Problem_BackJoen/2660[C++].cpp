// 회장뽑기
// https://www.acmicpc.net/problem/2660
#include<iostream>
#include<vector>
using namespace std;

void MySolution(){
    int N;
    int* arr;
    
    cin >> N;

    vector<int>* v = new vector<int>[N];
    arr = new int[N];
    while (true)
    {
        int temp1, temp2;
        cin >> temp1;
        cin >> temp2;
        if(temp1 == -1){
            break;
        }
        v[temp1].push_back(temp2);
        v[temp2].push_back(temp1);
    }
    int lower = N;
    int count = 0;
    for(int i=0; i<5;i++){
        if(lower > v[i].size()){
            lower = v[i].size();
        }
    }
    cout << lower << " ";

    for(int i=0; i<N;i++){
        if(lower > v[i].size()){
            lower = v[i].size();
        }
    }

    for(int i=0; i<N;i++){
        if(lower == v[i].size()){
            arr[count] = i;
            count++;
        }
    }
    cout << count << endl;

    for(int i=0; i<N;i++){
        cout << arr[i] << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();

}