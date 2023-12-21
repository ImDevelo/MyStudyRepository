//직사각형 네개의 합집합의 면적 구하기
//https://www.acmicpc.net/problem/2669
#include<iostream>
using namespace std;

#define MAX 100

bool arr[MAX][MAX];
int rect[4][4];


void MySolution(){
    for(int i=0; i<4;i++){
        for(int j=0; j<4;j++){
            cin >> rect[i][j];
        }
    }


    for(int i=0; i<4;i++){
        int x1 = rect[i][0] - 1;
        int y1 = rect[i][1] - 1;
        int x2 = rect[i][2] - 1;
        int y2 = rect[i][3] - 1;


        for(int j=x1; j<x2;j++){
            for(int k=y1; k<y2;k++){
                arr[k][j] = true;
            }
        }
    }



    int counting = 0;
    for(int i=0; i<MAX;i++){
        for(int j=0; j<MAX;j++){
            if(arr[i][j]){
                counting++;
            }
        }
    }
    cout << counting << endl;


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();

}