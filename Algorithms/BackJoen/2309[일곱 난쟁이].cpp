// 일곱난쟁이
// https://www.acmicpc.net/problem/2309
#include<iostream>
#include<algorithm>
using namespace std;

void MySolution(){
    int noom[9];
    for(int i=0; i<9;i++){
        cin >> noom[i];
    }

    int sum = 0;
    int i,j;
    for(i=0; i<8;i++){
        for(j=i+1; j<9 ;j++){
            if(i!=j){
                for(int k=0; k<9 ;k++){
                    if( k!=i && k !=j){
                        sum += noom[k]; 
                    }
                }

                if(sum == 100){
                        for(int x=0; x<9;x++){
        if( x == i || x == j ){
            noom[x] = 101;
        }
    }

    sort(&noom[0], &noom[9]);
    
    for(int x=0; x<7;x++){
        cout << noom[x] << " ";
    }
    return;
                }
                sum = 0;
            }
        }
    }


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();

}