//스택
//https://www.acmicpc.net/problem/10828
#include<iostream>
#include<string>
using namespace std;

class Stack{
public:
    Stack(){
        first = nullptr;
        stackSize = 0;
    }

    void push(int a){
        Node* temp = new Node(a);
        temp->next = nullptr;
        stackSize++;
        if(empty()){
            first = temp;
        }else{
            temp->next = first;
            first = temp;
        }
    }

    int pop(){
        if(empty()){
            return -1;
        }else{
            Node* p = first;
            int d = first->data;
            first = first->next;
            stackSize--;
            delete p;

            return d;
        }
    }

    int empty(){
        if(first == nullptr){
            return 1;
        }
        return 0;
    }

    int top(){
        if(empty()){
            return -1;
        }else{
            return first->data;
        }
    }

    int size(){
        return stackSize;
    }

private:
    class Node{
        Node(int a){
            data = a;
        }
        int data;
        Node* next;
        friend Stack;
    };
    
    Node* first;
    int stackSize;
};


void MySolution(){
    Stack s;
    string str;
    int N;
    cin >> N;
    for(int i =0; i<N; i++){
        cin >> str;
        if(str == "push"){
            int a;
            cin >> a;
            s.push(a);
        }else if(str == "pop"){
            cout << s.pop() << " ";
        }else if(str == "top"){
            cout << s.top() << " ";
        }else if(str == "size"){
            cout << s.size() << " ";
        }else if(str == "empty"){
            cout << s.empty() << " ";
        }
    }
    

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();

}