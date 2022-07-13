//감시
//https://www.acmicpc.net/problem/15683
#include<iostream>
using namespace std;
#define MAX 8

int R,C;
int area = 0, cctv_count;
int arr[MAX][MAX];
CCTV cctv[MAX];

class CCTV{
public:
    int r,c;
    int model;
    int type[5] = {4,2,4,4,1};

    CCTV(int _r, int _c, int _m){
        r = _r; c = _c; model = _m-1;
    }

    int getModel(){
        return model + 1;
    }

    int getType(){
        return type[model];
    }

};

void caseOfSurveillance(int count){
    if(count == cctv_count){
        cout << "!";
        return;
    }

    int c = cctv[0].getType();

    for(int i=0; i<c;i++){
        caseOfSurveillance(count+1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> R >> C;
    int index = 0;
    for(int i=0; i<R; i++){
        for(int j=0,t; j<C; j++){
            cin >> t;
            if(t > 0 && t < 6){
                cctv[index++] = new CCTV(i,j,t);
            }else if(t == 0){
                area++;
            }
        }
    }
    cctv_count = index-1;

    caseOfSurveillance(0);
}