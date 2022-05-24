#include <iostream>
using namespace std;

template <typename T>
class LinkedList{
public:
    LinkedList(){
        length = 0;
        first = nullptr;
        last = nullptr;
        Point = nullptr;  
    }

    void push(T n){
        Node* node = new Node(n);
        if(empty()){
            first = node;
            last = node;
            Point = node;
        }else{
            node->prev = last;
            last->next = node;
            last = node;
        }
        length++;
    }

    void pop(){
        if(!empty()){
            Node* temp = last;
            if(length == 1){
                first = nullptr;
                last = nullptr;
            }else{
                last = last->prev;
                last->next = nullptr;
            }
            delete last;
            length--;
        }
    }

    T front(){
        return first->data;
    }

    T end(){
        return last->data;
    }

    int size(){
        return length;
    }

    bool empty(){
        if(first == nullptr) return true;
        else return false;
    }

    void print(){
        Node* p = first;
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }

private:
    class Node{
        Node(T n){
            data = n;
            prev = nullptr;
            next = nullptr;
        }
        T data;
        Node* prev;
        Node* next;
        friend LinkedList;
    };
    int length;
    Node* first;
    Node* last;
    Node* Point;
};



int main(){
    LinkedList<int> l;

    l.push(1);
    l.push(5);
    l.push(111);
    l.print();
    l.pop();
    l.pop();
    l.pop();
    l.print();

}
