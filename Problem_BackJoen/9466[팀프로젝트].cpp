//텀 프로젝트
//https://www.acmicpc.net/problem/9466
#include<iostream>
#include<stack>
using namespace std;
#define MAX 100001

int arr[MAX];
bool check[MAX];

void TermProject(){
    int N, result = 0;//, *arr; 
    //bool* check;
    cin >> N;

 //   arr = new int[N];
//    check = new bool[N];
    for(int i=0,t; i<N; i++){
        cin >> t;
        arr[i] = (t-1);
        check[i] = false;
        if((t-1)==i){
            check[i] = true;
        }
    }

    //for(int i=0; i<N; i++){
    //    cout << arr[i] + 1 << " (" << check[i] << ") ";
    //} cout << endl;

    stack<int> s;
    for(int i=0; i<N; i++){
        int count = 0;
        if(check[i] == false){
            int point = i, index = i;
            for(int i=0; i<N; i++){
                if(check[index] == true){
                    point = index;
                    //cout << "point:" << point+1 <<" break;" << endl;
                    i=N;
                    continue;
                }
                //cout << index + 1 << " to ";
                s.push(index);
                check[index] = true;
                index = arr[index];
                //cout << index + 1 << " ... ";
            }
            while (!s.empty())
            {
                count++;
                if(s.top() == point){
                    count = 0;
                }
                //cout << "pop " << s.top()+1 << " ";
                s.pop();
            }

            //cout << endl;
        }
        result += count;
    }

    cout << result << "\n";

    //delete arr;
    //delete check;
    return;
}



void MySolution() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        TermProject();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    MySolution();
}