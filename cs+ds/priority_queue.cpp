#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class PriorityQueue {
private:
    std::vector<T> heap;

    // 힙 속성을 유지하기 위해 요소를 위로 올림
    void siftUp(int index) {
        while (index > 0 && heap[index] < heap[(index - 1) / 2]) {
            std::swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    // 힙 속성을 유지하기 위해 요소를 아래로 내림
    void siftDown(int index) {
        int size = heap.size();
        while (2 * index + 1 < size) {
            int smallest = 2 * index + 1;
            if (2 * index + 2 < size && heap[2 * index + 2] < heap[smallest]) {
                smallest = 2 * index + 2;
            }
            if (heap[index] <= heap[smallest]) {
                break;
            }
            std::swap(heap[index], heap[smallest]);
            index = smallest;
        }
    }

public:
    // 요소 삽입
    void push(const T& value) {
        heap.push_back(value);
        siftUp(heap.size() - 1);
    }

    // 가장 작은 요소 제거 및 반환
    T pop() {
        if (heap.empty()) {
            throw std::runtime_error("Priority queue is empty.");
        }
        T minValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            siftDown(0);
        }
        return minValue;
    }

    // 가장 작은 요소 반환
    T top() const {
        if (heap.empty()) {
            throw std::runtime_error("Priority queue is empty.");
        }
        return heap[0];
    }

    // 큐가 비어있는지 확인
    bool empty() const {
        return heap.empty();
    }

    // 큐의 크기 반환
    int size() const {
        return heap.size();
    }
};

int main() {
    PriorityQueue<int> pq;

    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);

    std::cout << "Priority queue contents (int): ";
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout << std::endl;

    PriorityQueue<std::string> pqStr;
    pqStr.push("apple");
    pqStr.push("banana");
    pqStr.push("cherry");
    pqStr.push("date");

    std::cout << "Priority queue contents (string): ";
    while (!pqStr.empty()) {
        std::cout << pqStr.top() << " ";
        pqStr.pop();
    }
    std::cout << std::endl;

    return 0;
}
