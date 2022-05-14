// 좌표 정렬하기 2
// https://www.acmicpc.net/problem/11651
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class XY{
    public:
    int x;
    int y;

    void print(){
         cout << x << " " << y << "\n";
    }
};

bool compare(XY a,XY b){
    if(a.y < b.y ||(a.y == b.y && a.x < b.x)){
        return true;
    }
    return false;
}

void MySolution(){
    int N;
    cin >> N;
    XY* x = new XY[N];
    for(int i=0; i<N; i++){
        cin >> x[i].x >> x[i].y;
    }
    sort(&x[0],&x[N],compare);
    for(int i=0; i<N; i++){
       x[i].print();
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();
}