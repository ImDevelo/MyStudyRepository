//암호만들기
//https://www.acmicpc.net/problem/1759
#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;
#define MAX 16

int L, C;
pair<char, bool> arr[MAX];
char code[MAX];


void combinaition(int n,int start,int vowel,int consonant){
    if(n==L){
        if(vowel >= 1 && consonant >= 2){
            for(int i=0; i<L;i++){
                cout << code[i]; 
            }
            cout << "\n";
            return;
        }
    }
    for(int i=start; i<C;i++){
        code[n] = arr[i].first;
        if(arr[i].second){
            combinaition(n+1, i+1, vowel + 1, consonant);
        }else{
            combinaition(n+1, i+1, vowel, consonant + 1);
        }
    }
    
}

void MySolution(){
    cin >> L >> C;
    char t;
    for(int i=0; i<C; i++){
        cin >> t;
        arr[i].first = t;
        if(t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u'){
            arr[i].second = true;
        }else{
            arr[i].second = false;
        }
    }
    sort(&arr[0], &arr[C]);
    combinaition(0,0,0,0);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    MySolution();
}