//수찾기
//https://www.acmicpc.net/problem/1920
#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
long *arr, *arr2;

int binarySerch(const long find, int high, int low){
    if(high < low){
        return 0;
    }
        
    
    int mid = (low + high) / 2;
    if(find == arr[mid]){
        return 1;
    }
    else if(find < arr[mid]){
        return binarySerch(find, mid-1, low);
    }
    else{
        return binarySerch(find, high, mid+1);
    }
}

void MySolution(){
    cin >> N;
    arr = new long[N];
    for(int i=0; i<N;i++){
        cin >> arr[i];
    }
    sort(&arr[0], &arr[N]);

    cin >> M;
    arr2 = new long[M];
    for(int i=0; i<M;i++){
        cin >> arr2[i];
    }


    for(int i=0; i<M;i++){
        //cout << binary_search(&arr[0], &arr[N], arr2[i]) << " ";

        cout << binarySerch(arr2[i], N-1,0) << " ";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();

}