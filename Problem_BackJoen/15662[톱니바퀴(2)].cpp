//톱니바퀴
//https://www.acmicpc.net/problem/14891
#include<iostream>
#include<math.h>
using namespace std;
class Sawtooth {
public:

    Sawtooth() {
        length = 0;
        first = nullptr;
        leftSaw = nullptr;
        rightSaw = nullptr;
        open = false;
    }

    void add(char n) {
        Node* node = new Node(n);
        length++;
        if (first == nullptr) {
            first = node;
            last = node;
        }
        else {
            node->prve = last;
            last->next = node;
            last = node;
            if (length == 3) {
                sideRight = node;
            }
            else if (length == 7) {
                sideLeft = node;
            }
            else if (length == 8) {
                node->next = first;
                first->prve = node;
            }
        }
    }

    void rollLeft() {
        open = true;
        if (leftSaw != nullptr && leftSaw->open == false) {
            if (sideLeft->data != leftSaw->sideRight->data) {
                leftSaw->rollRight();
            }

        }
        if (rightSaw != nullptr && rightSaw->open == false) {
            if (sideRight->data != rightSaw->sideLeft->data) {
                rightSaw->rollRight();
            }
        }
        Node* p = first;
        first = p->next;
        for (int i = 0; i < 8; i++) {
            p = p->next;
            if (i == 2) {
                sideRight = p;
            }
            else if (i == 6) {
                sideLeft = p;
            }
        }
        open = false;
    }

    void rollRight() {
        open = true;
        if (leftSaw != nullptr && leftSaw->open == false) {
            if (sideLeft->data != leftSaw->sideRight->data) {
                leftSaw->rollLeft();
            }

        }
        if (rightSaw != nullptr && rightSaw->open == false) {
            if (sideRight->data != rightSaw->sideLeft->data) {
                rightSaw->rollLeft();
            }
        }
        Node* p = first;
        first = p->prve;
        for (int i = 0; i < 8; i++) {
            p = p->next;
            if (i == 0) {
                sideRight = p;
            }
            else if (i == 4) {
                sideLeft = p;
            }
        }
        open = false;
    }

    char getTopvalue() {
        return first->data;
    }
    Sawtooth* leftSaw;
    Sawtooth* rightSaw;
    bool open;
private:
    class Node {
        Node(char n) {
            data = n;
            prve = nullptr;
            next = nullptr;
        }
        char data;
        Node* prve;
        Node* next;
        friend Sawtooth;
    };
    int length;
    Node* first;
    Node* last;
    Node* sideRight;
    Node* sideLeft;
};



void MySolution() {
    int N;
    cin >> N;
    Sawtooth* s = new Sawtooth[N];

    for(int i=0 ; i<N-1 ; i++){
        s[i].rightSaw = &s[i+1];
    }
    for(int i=1 ; i<N ; i++){
        s[i].leftSaw = &s[i-1];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 8; j++) {
            char temp;
            cin >> temp;
            s[i].add(temp);
        }
    }
    
    int K, a, b;
    cin >> K;
    for(int i=0; i<K;i++){
        cin >> a >> b;
        if(b == 1){
            s[a-1].rollRight();
        }else{
            s[a-1].rollLeft();
        }
    }
    int sum = 0;
    for (int i = 0; i < N; i++) {
        if (s[i].getTopvalue() == '1') {
            sum++;
        }
    }
    cout << sum << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();
}