//십자카드
//https://www.acmicpc.net/problem/2659
#include<iostream>
using namespace std;

int N;
int arr[4];


void MySolution(){
    for(int i =0; i<4;i++){
        cin >> arr[i];
    }
    for(int i=0; i<4;i++){
        for(int j=i;j<4;j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        } 
    }
    int ClockNumber = 1000*arr[0] + 100*arr[1] + 10*arr[2] + 1*arr[3];
    int count = 1;
    for(int i=1; i<=9; i++){
        for(int j=i;j<=9;j++){
            for(int k=j;k<=9;k++){
                for(int z=k;z<=9;z++){
                    int tempNumber = 1000*i + 100*j + 10*k+ 1*z;
                    if(ClockNumber > tempNumber){
                        cout << tempNumber << " ";
                        count++;
                    }
                }
            }
        }
    }
    cout << count;    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();

}