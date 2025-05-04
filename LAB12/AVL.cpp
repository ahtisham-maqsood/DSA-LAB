#include <iostream>
using namespace std;

class Node {
public:
    int data;
    int height;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
        height = 1;
    }
};

class AVL {
public:
    Node* root;

    AVL() {
        root = NULL;
    }

    int height(Node* n) {
        if (n == NULL) return 0;
        return n->height;
    }

    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    int getBalance(Node* n) {
        if (n == NULL) return 0;
        return height(n->left) - height(n->right);
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        y->left = x->right;
        x->right = y;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        y->left = x;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    Node* insert(Node* node, int key) {
        if (node == NULL) return new Node(key);

        if (key < node->data)
            node->left = insert(node->left, key);
        else if (key > node->data)
            node->right = insert(node->right, key);
        else
            return node;

        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);

        if (balance > 1 && key < node->left->data)
            return rightRotate(node);
        if (balance < -1 && key > node->right->data)
            return leftRotate(node);
        if (balance > 1 && key > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && key < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inorder(Node* r) {
        if (r != NULL) {
            inorder(r->left);
            cout << r->data << " ";
            inorder(r->right);
        }
    }

    void preorder(Node* r) {
        if (r != NULL) {
            cout << r->data << " ";
            preorder(r->left);
            preorder(r->right);
        }
    }

    void postorder(Node* r) {
        if (r != NULL) {
            postorder(r->left);
            postorder(r->right);
            cout << r->data << " ";
        }
    }

    void insertValue(int val) {
        root = insert(root, val);
    }

    void printTraversals() {
        cout << "Inorder: ";
        inorder(root);
        cout << "\nPreorder: ";
        preorder(root);
        cout << "\nPostorder: ";
        postorder(root);
        cout << endl;
    }
};

int main() {
    AVL tree;
    int n, x;
    cout << "Number of values: ";
    cin >> n;
    cout << "Enter values:\n";
    for (int i = 0; i < n; i++) {
        cin >> x;
        tree.insertValue(x);
    }

    tree.printTraversals();
    return 0;
}