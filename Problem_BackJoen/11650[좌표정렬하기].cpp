// 좌표 정렬하기
// https://www.acmicpc.net/problem/11650
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
    if(a.x < b.x ||(a.x == b.x && a.y < b.y)){
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

void AtherSolution(){
    vector<pair<int,int>> a;
    int b;
    scanf("%d",&b);
    
    for(int i=0;i<b;i++){
        int c,d;
        scanf("%d %d",&c,&d);
        a.push_back({c,d});
    }
    
    sort(a.begin(),a.end());
    for(int i=0;i<b;i++){
            printf("%d %d\n",a[i].first,a[i].second);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();
    AtherSolution();
}