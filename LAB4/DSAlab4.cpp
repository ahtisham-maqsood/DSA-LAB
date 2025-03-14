# include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtFront(int);
    void insertAtEnd(int);
    void insertAtPosition(int, int);
    void printList();
};
void LinkedList::insertAtFront(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}
void LinkedList::insertAtEnd(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}
void LinkedList::insertAtPosition(int position, int value) {
    Node* newNode = new Node(value);
    if (position <= 0) {
        cout << "Invalid position. Position must be greater than 0." << endl;
        delete newNode;
        return;
    }

    if (position == 1) {
        insertAtFront(value);
        return;
    }

    Node* temp = head;
    int currentPosition = 1;

    while (temp != nullptr && currentPosition < position - 1) {
        temp = temp->next;
        currentPosition++;
    }

    if (temp == nullptr) {
        cout << "Position out of bounds." << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void LinkedList::printList() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    LinkedList list;
    list.insertAtFront(57);
    list.insertAtFront(23);
    list.insertAtEnd(114);
    cout << "LinkedList after insertions: ";
    list.printList();

    list.insertAtPosition(3, 5000);
    cout << "LinkedList after inserting 50 at position 2: ";
    list.printList();


    return 0;
}
