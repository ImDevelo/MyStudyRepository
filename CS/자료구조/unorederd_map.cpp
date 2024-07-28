#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int STL_unordered_map() {
    // 초기화
    unordered_map<int, string> umap = {{1, "one"}, {2, "two"}, {3, "three"}};
    
    // 원소 추가
    umap[4] = "four"; // O(1) 평균, O(n) 최악
    umap.insert({5, "five"}); // O(1) 평균, O(n) 최악

    // 원소 삭제
    umap.erase(2); // O(1) 평균, O(n) 최악

    // 원소 순회 (range-based for)
    cout << "Elements:" << endl;
    for (const auto& pair : umap) { // O(n)
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
    }

    // 원소 검색
    auto it = umap.find(3); // O(1) 평균, O(n) 최악
    if (it != umap.end()) {
        cout << "Found key 3 with value: " << it->second << endl;
    } else {
        cout << "Key 3 not found." << endl;
    }

    // 자주 사용되지 않는 메서드들
    cout << "Bucket count: " << umap.bucket_count() << endl; // O(1)
    cout << "Load factor: " << umap.load_factor() << endl; // O(1)

    umap.max_load_factor(1.0); // O(1)
    cout << "Max load factor: " << umap.max_load_factor() << endl; // O(1)

    umap.rehash(20); // O(n)
    umap.reserve(50); // O(n)

    return 0;
}

#include <iostream>
#include <vector>
#include <list>
#include <functional> // for hash
#include <utility> // for pair

template <typename Key, typename Value>
class SimpleUnorderedMap {
private:
    vector<list<pair<Key, Value>>> table;
    hash<Key> hashFunction;
    size_t currentSize;
    const size_t initialBucketCount = 16;
    const float maxLoadFactor = 0.75;

    void rehash() {
        size_t newBucketCount = table.size() * 2;
        vector<list<pair<Key, Value>>> newTable(newBucketCount);

        for (const auto& bucket : table) {
            for (const auto& kvp : bucket) {
                size_t newIndex = hashFunction(kvp.first) % newBucketCount;
                newTable[newIndex].push_back(kvp);
            }
        }

        table = move(newTable);
    }

public:
    SimpleUnorderedMap() : table(initialBucketCount), currentSize(0) {}

    bool insert(const Key& key, const Value& value) {
        if (currentSize > table.size() * maxLoadFactor) {
            rehash();
        }

        size_t index = hashFunction(key) % table.size();
        for (auto& kvp : table[index]) {
            if (kvp.first == key) {
                kvp.second = value;
                return false;
            }
        }

        table[index].emplace_back(key, value);
        ++currentSize;
        return true;
    }

    bool erase(const Key& key) {
        size_t index = hashFunction(key) % table.size();
        auto& bucket = table[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                --currentSize;
                return true;
            }
        }
        return false;
    }

    Value* find(const Key& key) {
        size_t index = hashFunction(key) % table.size();
        for (auto& kvp : table[index]) {
            if (kvp.first == key) {
                return &kvp.second;
            }
        }
        return nullptr;
    }

    size_t size() const {
        return currentSize;
    }

    bool empty() const {
        return currentSize == 0;
    }
};

int main() {
    SimpleUnorderedMap<int, string> myMap;

    // Insert elements
    myMap.insert(1, "one");
    myMap.insert(2, "two");
    myMap.insert(3, "three");

    // Find element
    if (auto* value = myMap.find(2)) {
        cout << "Found key 2 with value: " << *value << endl;
    } else {
        cout << "Key 2 not found." << endl;
    }

    // Erase element
    myMap.erase(2);

    // Find element again
    if (auto* value = myMap.find(2)) {
        cout << "Found key 2 with value: " << *value << endl;
    } else {
        cout << "Key 2 not found." << endl;
    }

    return 0;
}
