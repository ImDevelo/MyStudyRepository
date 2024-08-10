//에디터
//https://www.acmicpc.net/problem/1406
#include <iostream>
#include <string>
using namespace std;

#include <iostream>
#include <string>

// 노드 클래스 정의
class Node {
public:
    char data;        // 노드에 저장할 데이터 (문자)
    Node* next;      // 다음 노드를 가리키는 포인터
    Node* prev;      // 이전 노드를 가리키는 포인터

    // 생성자
    Node(char value) : data(value), next(nullptr), prev(nullptr) {}
};

// 양방향 링크드 리스트 클래스 정의
class LineEditor {
private:
    Node* head; // 리스트의 첫 번째 노드를 가리키는 포인터
    Node* tail; // 리스트의 마지막 노드를 가리키는 포인터

public:
    // 생성자
    LineEditor() : head(nullptr), tail(nullptr) {}

    // 소멸자
    ~LineEditor() {
        Node* current = head;
        Node* nextNode;
        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // 리스트의 끝에 새 노드 추가
    void append(char value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // 리스트의 시작에 새 노드 추가
    void prepend(char value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // 리스트의 모든 노드 출력
    void printListForward() const {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " <-> ";
            temp = temp->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    // 리스트의 모든 노드 출력 (역방향)
    void printListBackward() const {
        Node* temp = tail;
        while (temp != nullptr) {
            std::cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        std::cout << "nullptr" << std::endl;
    }
};



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    LineEditor list;
    std::string input;

    // 사용자로부터 문자열 입력 받기
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    // 입력받은 문자열의 각 문자 리스트에 추가
    for (char c : input) {
        list.append(c);
    }

    // 리스트 출력
    std::cout << "List Forward: ";
    list.printListForward();
    std::cout << "List Backward: ";
    list.printListBackward();

    for(int i=0; i<10; i++){
        char command;
        cin >> command;

        switch (command)
        {
        case 'L':
            if(1 > 0){

            }
            break;
        case 'D':

            break;

        case 'B':

            break;

        case 'P':

            break;

        
        default:


            break;
        }




    }
}