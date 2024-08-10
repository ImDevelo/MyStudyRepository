//Test

#include<iostream>
using namespace std;
#define MAX 999

void MySolution(){
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            if(i%2 == 0){
                cout << "0";
            }else{
                if((j == 0 && i % 2 == 1 )){
                    cout << "0";
                }else{
                    cout << "1";
                }
                
            }
            

        }
        cout << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    MySolution();
}