// AC
// https://www.acmicpc.net/problem/5430
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

template <typename T>
class LinkedList{
public:
    LinkedList(){
        first = nullptr;
        last = nullptr;
        lenght = 0;
        rev = false;
    }

    void add(T c){
        Node* p = new Node(c);
        lenght++;
        if(first == nullptr){
            first = p;
            last = p;
        }else{
            p->prv = last;
            last->next = p;
            last = p;
        }
    }

    void Delete(){
        if(lenght == 1){
            first = nullptr;
            last = nullptr;
            lenght = 0;
        }else{
            lenght--;
        if(!rev){
            Node* temp = first;
            first = first->next;
            first->prv = nullptr;
            
            delete temp;
        }else{
            Node* temp = last;
            last = last->prv;
            last->next = nullptr;

            delete temp;
        }
        }
    }

    void Reverse(){
        rev = !rev;
    }

    bool empty(){
        if(first == nullptr) return true;
        return false;
    }

    void print(){
        if(rev){
            Node* p = last;
            cout << "[";
            if(p != nullptr){
                 while (p->prv != nullptr)
                {
                    cout << p->data << ",";
                    p = p->prv;
                }
                cout << p->data;
            }
            cout << "]\n";
        }else{
            Node* p = first;
            cout << "[";
            if(p != nullptr){
                 while (p->next != nullptr)
                {
                    cout << p->data << ",";
                    p = p->next;
                }
                cout << p->data;
            }
            cout << "]\n";

        }
    }

private:
    class Node{
        Node(T c){
            prv = nullptr;
            next = nullptr;
            data = c;
        }
        T data;
        Node* prv;
        Node* next;
        friend LinkedList;
    };
    Node* first;
    Node* last;
    int lenght;

    bool rev;

};


void algorisum() {
    int N;
    string p, num;
    cin >> p >> N;
    LinkedList<string> l;

    if (N > 0) {
        cin >> num;
        num.erase(0, 1); num.erase(num.length() - 1, 1); //대괄호 제거

        int start = 0;
        int d = num.find(',');

        while (d != -1)
        {
            l.add(num.substr(start, d - start));
            start = d + 1;
            d = num.find(',', start);
        }
        l.add(num.substr(start, d - start));
    }else{
        cin >> num;
        num = "";
    }


    for (int i = 0; i < p.length(); i++) {
        if (p.at(i) == 'R') { //반대로
            l.Reverse();
        }
        else if (p.at(i) == 'D') { //삭제
            if(l.empty()){
                cout << "error\n";
                return;
            }
            l.Delete();
        }
    }
    l.print();
}

void MySolution() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        algorisum();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();
}