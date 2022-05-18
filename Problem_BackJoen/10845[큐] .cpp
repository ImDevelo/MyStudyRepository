//큐
//https://www.acmicpc.net/problem/10845
#include<iostream>
#include<string>
using namespace std;

class Queue{
public:
    Queue(){
        first = nullptr;
        queueSize = 0;
    }

    void push(int a){
        Node* temp = new Node(a);
        temp->next = nullptr;
        queueSize++;
        if(empty()){
            first = temp;
            last = temp;
        }else{
            last->next = temp;
            last = temp;
        }
    }

    int pop(){
        if(empty()){
            return -1;
        }else{
            Node* p = first;
            int d = first->data;
            first = first->next;
            queueSize--;
            delete p;

            return d;
        }
    }

    int front(){
        if(empty()){
            return -1;
        }else{
            return first->data;
        }
    }

    int back(){
        if(empty()){
            return -1;
        }else{
            return last->data;
        }
    }

    int empty(){
        if(first == nullptr){
            return 1;
        }
        return 0;
    }

    int size(){
        return queueSize;
    }

private:
    class Node{
        Node(int a){
            data = a;
        }
        int data;
        Node* next;
        friend Queue;
    };
    
    Node* first;
    Node* last;
    int queueSize;
};


void MySolution(){
    Queue q;
    string str;
    int N;
    cin >> N;
    for(int i =0; i<N; i++){
        cin >> str;
        if(str == "push"){
            int a;
            cin >> a;
            q.push(a);
        }else if(str == "pop"){
            cout << q.pop() << " ";
        }else if(str == "front"){
            cout << q.front() << " ";
        }else if(str == "back"){
            cout << q.back() << " ";
        }else if(str == "size"){
            cout << q.size() << " ";
        }else if(str == "empty"){
            cout << q.empty() << " ";
        }
    }
    

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();

}