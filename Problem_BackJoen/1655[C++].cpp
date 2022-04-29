//[가운데를 말해요]
//https://www.acmicpc.net/problem/1655

#include<iostream>
using namespace std;

#define MAX_NUMBER 100000

int number[MAX_NUMBER];
int minHeap[MAX_NUMBER];
int maxHeap[MAX_NUMBER];
int minIndex = 0;
int maxIndex = 0;


void inputMaxHeap(int n){
    maxHeap[maxIndex] = n;
    for(int i =0; i<maxIndex;i++){
        if(i){

        }

    }

}

void inputMinHeap(int n){

}


int main(){
    int N;
    cin >> N;

    cin >> maxHeap[1];
    maxIndex = 1;

    int temp;
    for(int i =0; i<N;i++){
        cin >> temp;
        if(maxHeap[1] >= temp ){
            if(minIndex < maxIndex){
                inputMaxHeap(temp);
            }else{
                inputMaxHeap(temp);
            }
        }else if(maxHeap[1] < temp){
            if(minIndex > maxIndex){
                inputMaxHeap(temp);
            }else{
                inputMaxHeap(temp);
            }
        }else{
            

        }
    }



    
    return 0;
}
