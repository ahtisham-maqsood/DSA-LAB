#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class QueueNode {
public:
    Node* data;
    QueueNode* next;
    QueueNode(Node* d) {
        data = d;
        next = NULL;
    }
};

class Queue {
    QueueNode* front;
    QueueNode* rear;

public:
    Queue() {
        front = rear = NULL;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void enqueue(Node* data) {
        QueueNode* temp = new QueueNode(data);
        if (rear == NULL) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    Node* dequeue() {
        if (isEmpty()) return NULL;

        QueueNode* temp = front;
        Node* data = front->data;
        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;
        return data;
    }
};

class Tree {
public:
    Node* root;

    Tree() {
        root = NULL;
    }

    Node* insert(Node* node, int val) {
        if (node == NULL)
            return new Node(val);
        if (val < node->data)
            node->left = insert(node->left, val);
        else
            node->right = insert(node->right, val);
        return node;
    }

    void BFS() {
        if (root == NULL) return;

        Queue q;
        q.enqueue(root);

        while (!q.isEmpty()) {
            Node* current = q.dequeue();
            cout << current->data << " ";

            if (current->left != NULL)
                q.enqueue(current->left);
            if (current->right != NULL)
                q.enqueue(current->right);
        }
    }
};

int main() {
    Tree tree;
    tree.root = tree.insert(tree.root, 40);
    tree.insert(tree.root, 5);
    tree.insert(tree.root, 10);
    tree.insert(tree.root, 15);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 25);
    tree.insert(tree.root, 30);

    cout << "Traversal: ";
    tree.BFS();

    return 0;
}