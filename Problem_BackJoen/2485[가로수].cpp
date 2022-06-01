//가로수
//https://www.acmicpc.net/problem/2485
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<long> v;
vector<int> d;
int N , max = 0;


int A(int x){
    for(int j=x-1; j>=1 ;j--){
        if(x%j == 0){
            return j;
        }
    }
    return 1;
}

void MySolution(){
    cin >> N;
    for(int i=0, temp; i<N;i++){
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    for(int i=0; i<N-1;i++){
        d.push_back(v.at(i+1)-v.at(i));
    }
    int x = d[0]; 
    for(int i=1; i < N-1; i++){
        if(d[i] % x != 0){
            x = A(x);
            i = 0; 
        }
    }
    long point = v[0];
    int counting = 0;
    for(int i=1; i < N; i++){
        point += x;
        while (point != v[i])
        {
            point += x;
            counting++;
        }
    }
    cout << counting;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();

}