//덱
//https://www.acmicpc.net/problem/10845
#include<iostream>
#include<string>
using namespace std;

class Deque{
public:
    Deque(){
        first = nullptr;
        last = nullptr;
        dequeSize = 0;
    }

    void push_front(int a){
        Node* temp = new Node(a);
        temp->next = nullptr;
        dequeSize++;
        if(empty()){
            first = temp;
            last = temp;
        }else{
            temp->next = first;
            first = temp;
        }
    }

    void push_back(int a){
        Node* temp = new Node(a);
        temp->next = nullptr;
        dequeSize++;
        if(empty()){
            first = temp;
            last = temp;
        }else{
            last->next = temp;
            last = temp;
        }
    }

    int pop_front(){
        if(empty()){
            return -1;
        }else if(dequeSize == 1){
            int d = first->data;
            delete last;
            first = nullptr;
            last = nullptr;
            dequeSize--;
            return d;
        }else{
            Node* p = first;
            int d = first->data;
            first = first->next;
            dequeSize--;
            delete p;

            return d;
        }
    }

    int pop_back(){
        if(empty()){
            return -1;
        }else if(dequeSize == 1){
            int d = first->data;
            delete last;
            first = nullptr;
            last = nullptr;
            dequeSize--;
            return d;
        }
        else{
            Node* p = first;
            Node* x = last;
            int d = last->data;
            for(int i=2; i<dequeSize; i++){
                p = p->next;
            }
            last = p;
            last->next = nullptr;
            dequeSize--;
            delete x;

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
        if(first == nullptr || last == nullptr){
            return 1;
        }
        return 0;
    }

    int size(){
        return dequeSize;
    }

private:
    class Node{
        Node(int a){
            data = a;
        }
        int data;
        Node* next;
        friend Deque;
    };
    
    Node* first;
    Node* last;
    int dequeSize;
};


void MySolution(){
    Deque d;
    string str;
    int N;
    cin >> N;
    for(int i =0; i<N; i++){
        cin >> str;
        if(str == "push_front"){
            int a;
            cin >> a;
            d.push_front(a);
        }else if(str == "push_back"){
            int a;
            cin >> a;
            d.push_back(a);
        }else if(str == "pop_front"){
            cout << d.pop_front() << " ";
        }else if(str == "pop_back"){
            cout << d.pop_back() << " ";
        }else if(str == "front"){
            cout << d.front() << " ";
        }else if(str == "back"){
            cout << d.back() << " ";
        }else if(str == "size"){
            cout << d.size() << " ";
        }else if(str == "empty"){
            cout << d.empty() << " ";
        }
    }
    

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();

}