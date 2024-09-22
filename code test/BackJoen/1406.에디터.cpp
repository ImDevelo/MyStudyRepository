//https://www.acmicpc.net/problem/1406
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Editor {
    
    class Node {
    public:
        char data;
        Node* next = nullptr;
        Node* prev = nullptr;
    };

    Node* head = nullptr;
    Node* curser = nullptr;
    Node* last = nullptr;

public:

    Editor(string str) {
        str += '\n';
        for (char c : str) {
            Node* newNode = new Node;
            newNode->data = c;

            if (last == nullptr) {
                head = newNode;
            }
            else {
                newNode->prev = last;
                last->next = newNode;
            }
            last = newNode;
        }
        curser = last;
    }

    void cmdL() {
        if (curser->prev != nullptr) {
            curser = curser->prev;
        }
    }

    void cmdD() {
        if (curser->next != nullptr) {
            curser = curser->next;
        }
    }

    void cmdB() {
        if (curser->prev != nullptr) {
            Node* deleteNode = curser->prev;
            Node* prevNode = deleteNode->prev;
            curser->prev = prevNode;
            if (prevNode == nullptr) {
                head = curser;
            }
            else {
                prevNode->next = curser;
            }
            delete deleteNode;
        }
    }

    void cmdP(char n) {
        Node* newNode = new Node;
        newNode->data = n;
        newNode->next = curser;
        newNode->prev = curser->prev;
        if (curser->prev != nullptr) {
            curser->prev->next = newNode;
        }
        curser->prev = newNode;

        if (curser == head) {
            head = newNode;
        }
        
    }

    void print() {
        
        Node* pointer = head;
        while (pointer != nullptr)
        {
            cout << pointer->data;
            pointer = pointer->next;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string str;
    int T;
    cin >> str >> T;

    Editor editor(str);

    while (T--)
    {
        char cmd;
        cin >> cmd;

        switch (cmd)
        {
        case 'L':
            editor.cmdL();
            break;
        case 'D':
            editor.cmdD();
            break;
        case 'B':
            editor.cmdB();
            break;
        case 'P':
            char n;
            cin >> n;
            editor.cmdP(n);
            break;
        default:
            break;
        }
    }
    editor.print();
}