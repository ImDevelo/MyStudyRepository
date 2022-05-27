//숫자 고르기
//https://www.acmicpc.net/problem/2668
#include<iostream>
using namespace std;
#define MAX 100

void MySolution(){
    int N;
    int arr[MAX];
    int count = 0;
    cin >> N;
    
    for(int i=0; i<N;i++){
        int temp;
        cin >> temp;
        arr[i] = temp - 1;
    }

    int check[MAX];

    for(int i=0; i<N;i++){
        if(check[i] != true){
            int p = arr[i];
            for(int j =0; j<N ; j++){
                if(arr[p] == i){
                    check[i] = true;
                    count++;
                    break;
                }
                p = arr[p]; 
            }

            if(check[i] == true){
                int x = arr[i];
                while (x != i)
                {
                    count++;

                    check[x] = true;
                    x = arr[x];
                }
            }
        }
    }
    cout << count << endl;
    for(int i =0; i<N;i++){
        if(check[i] == true){
            cout << i + 1 << endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();
}