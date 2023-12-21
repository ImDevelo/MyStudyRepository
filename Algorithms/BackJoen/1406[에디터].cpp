//에디터
//https://www.acmicpc.net/problem/1406
#include<iostream>
#include<string>
using namespace std;

class LinkedList{
public:
    LinkedList(){
        first = nullptr;
        last = nullptr;
        cuser = 0;
        lenght = 0;
    }

    void add(char c){
        Node* p = new Node(c);
        lenght++;
        cuser++;
        if(first == nullptr){
            first = p;
            last = p;
        }else{
            p->prv = last;
            last->next = p;
            last = p;
        }
    }

    void insert(char c){
        if(lenght > 0){
            Node* node = new Node(c);
            if(cuser == 0){
                node->next = first;
                first->prv = node;
                first = node;
            }else{
                Node* p = first;
                for(int i=1;i<cuser;i++){
                    p = p->next;
                }
                node->next = p->next;
                p->next = node;
                node->prv = p;
            }
            cuser++; lenght++;
        }
        
    }

    void Delete(){
        if(cuser > 0){
            if(cuser == 1){
                Node* temp = first;
                first = first->next;
                first->prv = nullptr;
                delete temp;
            }else{
                Node* p = first;
                for(int i=1; i<cuser;i++){
                    p = p->next;
                }
                Node* temp = p;
                Node* privous = p->prv;
                if(p->next == nullptr){
                    privous->next = nullptr;
                }else{
                    privous->next = p->next;
                    p->next->prv = privous;
                }
                delete temp;
            }
            cuser--;
            lenght--;
        }
    }

    void Left(){
        if(cuser > 0){
            cuser--;
        }
    }

    void Right(){
        if(cuser < lenght){
            cuser++;
        }
    }

    void print(){
        Node* p = first;
        for(int i=0; p != nullptr ;i++){
            cout << p->data;
            p = p->next;
        }

    }

private:
    class Node{
        Node(char c){
            prv = nullptr;
            next = nullptr;
            data = c;
        }
        char data;
        Node* prv;
        Node* next;
        friend LinkedList;
    };
    Node* first;
    Node* last;
    int lenght;
    int cuser;
};


void MySolution(){
    LinkedList l;
    string s;
    int N;
    char c;
    cin >> s;
    for(int i=0; i<s.length();i++){
        l.add(s.at(i));
    }

    cin >> N;
    for(int i=0; i<N;i++){
        cin >> c;
        switch (c)
        {
        case 'L':
            l.Left();
            break;
        case 'D':
            l.Right();
            break;
        case 'B':
            l.Delete();
            break;
        case 'P':
            cin >> c;
            l.insert(c);
            break;
        default:
            break;
        }
    }
    

    l.print();

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();
}