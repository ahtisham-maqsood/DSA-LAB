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
    LinkedList(){
        head=nullptr;
    }
    void insertAtFront(int );
    void insertAtEnd(int );
    void insertAtPosition(int , int);
    void printList();
    void printFirstNode();
    void printLastNode();
    void printNthNode(int n);
    void printCenterNode();
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

void LinkedList::printFirstNode() {
    if (head != nullptr) {
        cout << "First node data: " << head->data << endl;
    } else {
        cout << "The list is empty." << endl;
    }
}

void LinkedList::printLastNode() {
    if (head == nullptr) {
        cout << "The list is empty." << endl;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    cout << "Last node data: " << temp->data << endl;
}

void LinkedList::printNthNode(int n) {
    if (n <= 0) {
        cout << "Invalid position. Position must be greater than 0." << endl;
        return;
    }
    Node* temp = head;
    int currentPosition = 1;
    while (temp != nullptr && currentPosition < n) {
        temp = temp->next;
        currentPosition++;
    }
    if (temp == nullptr) {
        cout << "Position out of bounds." << endl;
    } else {
        cout << "Data at position " << n << ": " << temp->data << endl;
    }
}

void LinkedList::printCenterNode() {
    if (head == nullptr) {
        cout << "The list is empty." << endl;
        return;
    }
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "Center node data: " << slow->data << endl;
}

int main() {
    LinkedList list;
    list.insertAtFront(1);
    list.insertAtFront(2);
    list.insertAtFront(3);
    list.insertAtEnd(4);
    list.insertAtEnd(5);
    list.insertAtEnd(6);
    list.insertAtPosition(5, 25537);

    cout << "LinkedList: ";
    list.printList();

    list.printFirstNode();
    list.printLastNode();
    list.printNthNode(5);
    list.printCenterNode();

    return 0;
}
