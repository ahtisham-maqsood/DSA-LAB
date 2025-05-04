#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class StackLinkedList {
    Node* top;

public:
    StackLinkedList() {
        top = NULL;
    }

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
        cout << val << " pushed to stack\n";
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow\n";
            return;
        }
        cout << top->data << " popped from stack\n";
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void display() {
        if (top == NULL) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements: ";
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    StackLinkedList stack;
    stack.push(13);
    stack.push(24);
    stack.push(33);
    stack.display();
    stack.pop();
    stack.display();
    return 0;
}
