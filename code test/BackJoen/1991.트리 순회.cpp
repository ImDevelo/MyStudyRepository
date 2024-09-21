//https://www.acmicpc.net/problem/1991
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
    char data;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(int data) :data(data) {}
};

unordered_map<char, Node*> tree;

Node* create_node(char v) {
    if (v == '.') nullptr;
    else if (tree.find(v) == tree.end()) {
        tree[v] = new Node(v);
    }
    return tree[v];
}

void insert(char data, char left, char right) {
    Node* node = create_node(data);
    node->left = create_node(left);
    node->right = create_node(right);
}

void preorder(Node* node) {
    if (node == nullptr) return;
    cout << node->data;
    preorder(node->left);
    preorder(node->right);
}

void inorder(Node* node) {
    if (node == nullptr) return;
    inorder(node->left);
    cout << node->data;
    inorder(node->right);
}

void postorder(Node* node) {
    if (node == nullptr) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        char a, b, c;
        cin >> a >> b >> c;
        insert(a, b, c);
    }

    auto root = (*tree.find('A')).second;
    preorder(root);
    cout << "\n";
    inorder(root);
    cout << "\n";
    postorder(root);
}



