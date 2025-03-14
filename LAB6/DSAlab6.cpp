#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }
   
  


    void deleteFirst() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteLast() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* secondLast = head;
        while (secondLast->next && secondLast->next->next) {
            secondLast = secondLast->next;
        }
        delete secondLast->next;
        secondLast->next = nullptr;
    }
    void deleteNth(int n) {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        if (n == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        int count = 1;
        while (temp && count < n - 1) {
            temp = temp->next;
            count++;
        }
        if (temp == nullptr || temp->next == nullptr) {
            cout << "Position out of bounds" << endl;
            return;
        }
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    void deleteCenter() {
        if (head == nullptr || head->next == nullptr) {
            cout << "List is too small to have a center" << endl;
            return;
        }
        Node* slow = head;
        Node* fast = head;
        Node* prev = nullptr;
        while (fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        if (prev) {
            prev->next = slow->next;
        }
        delete slow;
    }
};

int main() {
  

    return 0;
}
