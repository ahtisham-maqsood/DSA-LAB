#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Tree {
public:
    Node* root;

    Tree() {
        root = NULL;
    }

    Node* insert(Node* node, int val) {
        if (node == NULL) {
            return new Node(val);
        }

        if (val < node->data) {
            node->left = insert(node->left, val);
        } else {
            node->right = insert(node->right, val);
        }

        return node;
    }

    void insertNode(int val) {
        root = insert(root, val);
    }

    void DFS(Node* node) {
        if (node == NULL)
            return;

        cout << node->data << " ";
        DFS(node->left);
        DFS(node->right);
    }

    void DFS_Traversal() {
        cout << "Traversal: ";
        DFS(root);
        cout << endl;
    }
};

int main() {
    Tree t;
    t.insertNode(1);
    t.insertNode(3);
    t.insertNode(5);
    t.insertNode(7);
    t.insertNode(9);
    t.insertNode(12);
    t.insertNode(15);

    t.DFS_Traversal();

    return 0;
}