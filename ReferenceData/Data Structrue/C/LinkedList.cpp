#include<iostream>
#include<list>
using namespace std;

class List {
private:
    class Node {
    public:
        int data;
        Node* next;
    };
    Node* first = nullptr; // 첫번째 노드
    Node* end = nullptr;
public:
    void insert(int index, int data) {
        if (index == 1) {
            Node* temp = new Node;
            temp->data = data;
            temp->next = first;
            first = temp;
        }
        else {
            Node* p = first;
            for (int i = 0; i < index - 2; i++) {
                if (p == nullptr) {
                    return;
                }
                p = p->next;
            }
            Node* temp = new Node;
            temp->data = data;
            temp->next = p->next;
            p->next = temp;
        }
        
    }

    void addNode(int data) {
        Node* temp = new Node;
        if (first == nullptr) {//첫번째 노드가 없는경우
            temp->data = data;
            temp->next = nullptr;
            first = temp;
        }
        else {//노드가 있는 경우 삽입 (첫번째 위치)
            temp->data = data;
            temp->next = first;
            first = temp;
        }
    }

    void print() {
        Node* p = first;

        while (p != nullptr)
        {
            cout << p->data << endl;
            p = p->next;
        }
       
    }
};

int main() {
    List l;
    l.addNode(1);
    l.addNode(2);
    l.addNode(3);
    l.insert(2,5);
    l.print();
}
