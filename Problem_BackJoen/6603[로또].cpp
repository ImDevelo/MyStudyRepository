#include<iostream>
using namespace std;

#define MAX 14
int num[MAX];
int arr[MAX];
int N;

void algorisum(int count, int start, int end){
    if(count == 6){
        for(int i=0;i<6;i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
    }else{
        for(int i=start; i<end;i++){
            arr[count] = num[i];
            algorisum(count + 1, i+1, end+1);
        }
    }
    return;
}

void MySolution(){
    while (true)
    {
        cin >> N;
        if(N == 0)
            return;
        for(int i=0; i<N;i++){
            cin >> num[i];
        }
        algorisum(0,0,N-5);
        cout << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();
}