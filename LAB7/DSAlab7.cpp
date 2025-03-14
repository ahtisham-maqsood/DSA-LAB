#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int data) {
        this->data = data;
        next = prev = nullptr;
    }
};
class DoublyLinkedList {
public:
    Node* head;
    Node* tail;
  DoublyLinkedList() {
        head = tail = nullptr;
    }
    void insertFirst(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void insertLast(int data) {
        Node* newNode = new Node(data);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void insertNth(int data, int position) {
        if (position <= 0) {
            cout << "Invalid position" << endl;
            return;
        }
        if (position == 1) {
            insertFirst(data);
            return;
        }
        
        Node* newNode = new Node(data);
        Node* temp = head;
        int count = 1;

        while (temp && count < position - 1) {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr) {
            cout << "Position out of bounds!" << endl;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        } else {
            tail = newNode;
        }

        temp->next = newNode;
    }
    void insertCenter(int data) {
        if (head == nullptr) {
            insertFirst(data);
            return;
        }

        Node* slow = head;
        Node* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            if (fast != nullptr) slow = slow->next;
        }

        if (slow == nullptr) {
            insertFirst(data);
        } else {
            Node* newNode = new Node(data);
            newNode->next = slow->next;
            newNode->prev = slow;

            if (slow->next != nullptr) {
                slow->next->prev = newNode;
            } else {
                tail = newNode;
            }

            slow->next = newNode;
        }
    }

    void displayForward() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "None" << endl;
    }

    void displayReverse() {
        Node* temp = tail;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "None" << endl;
    }
};

int main() {
    DoublyLinkedList dLList;

    dLList.insertFirst(12);
    dLList.insertFirst(26);
    dLList.insertLast(56);
    dLList.insertLast(478);
    dLList.insertNth(25, 3); 
    dLList.insertCenter(35);   
    dLList.displayForward();
    dLList.displayReverse();

    return 0;
}
