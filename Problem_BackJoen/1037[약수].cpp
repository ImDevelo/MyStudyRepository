#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void MySolution(){
    int N;
    cin >> N;

    vector<int> v;
    for(int i=0, temp; i<N;i++){
        cin >> temp;
        v.push_back(temp);
    }
    int value = 0;
    if(v.size() == 1){
        value = (v[0]*v[0]);
    }else{
        sort(v.begin(),v.end());
        value = v[0]*v[v.size()-1];
    }
    cout << value;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();

}