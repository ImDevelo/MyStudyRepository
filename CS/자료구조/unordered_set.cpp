#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

//해시 테이블(Hash Table)
int STL_unordered_set() {
    // 초기화 (O(n) - 초기화 시 모든 원소 삽입)
    unordered_set<int> uset = {1, 2, 3, 4, 5};

    // 원소 추가 (O(1) 평균)
    uset.insert(6);

    // 원소 삭제 (O(1) 평균)
    uset.erase(3);

    // 원소 순회 (O(n))
    cout << "Elements: ";
    for (const auto& elem : uset) {
        cout << elem << " ";
    }
    cout << endl;

    // 원소 검색 (O(1) 평균)
    auto it = uset.find(2);
    if (it != uset.end()) {
        cout << "Element found: " << *it << endl;
    } else {
        cout << "Element not found." << endl;
    }

    // 자주 사용되지 않는 메서드들
    cout << "Bucket count: " << uset.bucket_count() << endl; // O(1)
    cout << "Load factor: " << uset.load_factor() << endl; // O(1)
    
    uset.max_load_factor(1.0); // O(1)
    cout << "Max load factor: " << uset.max_load_factor() << endl; // O(1)

    uset.rehash(20); // O(n)
    uset.reserve(50); // O(n)

    return 0;
}


#include <iostream>
#include <vector>
#include <list>
#include <functional> // for hash

template <typename Key>
class SimpleUnorderedSet {
private:
    vector<list<Key>> table;
    hash<Key> hashFunction;
    size_t currentSize;
    const size_t initialBucketCount = 16; // 초기 버킷 수
    const float maxLoadFactor = 0.75; // 최대 로드 팩터

    void rehash() {
        size_t newBucketCount = table.size() * 2;
        vector<list<Key>> newTable(newBucketCount);

        for (const auto& bucket : table) {
            for (const auto& key : bucket) {
                size_t newIndex = hashFunction(key) % newBucketCount;
                newTable[newIndex].push_back(key);
            }
        }

        table = move(newTable);
    }

public:
    SimpleUnorderedSet() : table(initialBucketCount), currentSize(0) {}

    bool insert(const Key& key) {
        if (currentSize > table.size() * maxLoadFactor) {
            rehash();
        }

        size_t index = hashFunction(key) % table.size();
        for (const auto& k : table[index]) {
            if (k == key) {
                return false; // 이미 존재하는 원소
            }
        }

        table[index].push_back(key);
        ++currentSize;
        return true;
    }

    bool erase(const Key& key) {
        size_t index = hashFunction(key) % table.size();
        auto& bucket = table[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (*it == key) {
                bucket.erase(it);
                --currentSize;
                return true;
            }
        }
        return false;
    }

    bool contains(const Key& key) const {
        size_t index = hashFunction(key) % table.size();
        for (const auto& k : table[index]) {
            if (k == key) {
                return true;
            }
        }
        return false;
    }

    size_t size() const {
        return currentSize;
    }

    bool empty() const {
        return currentSize == 0;
    }
};

int main() {
    SimpleUnorderedSet<int> mySet;

    // 원소 추가
    mySet.insert(1);
    mySet.insert(2);
    mySet.insert(3);

    // 원소 확인
    cout << "Contains 2? " << (mySet.contains(2) ? "Yes" : "No") << endl;

    // 원소 삭제
    mySet.erase(2);

    // 원소 확인
    cout << "Contains 2? " << (mySet.contains(2) ? "Yes" : "No") << endl;

    return 0;
}
