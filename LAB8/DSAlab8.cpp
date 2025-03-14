#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int d) {
         data=d;
        prev = NULL;
        next = NULL;
    }
};

class DoublylinkedList  {
public:
    Node* head;
    Node* tail;

    DoublylinkedList () {
        head = NULL;
        tail = NULL;
    }

    void insertLast(int d) {
        Node* newNode = new Node(d);
        if (head == NULL) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void mergeList(DoublylinkedList & list2) {
        if (head == NULL) {
            head = list2.head;
            tail = list2.tail;
            return;
        }
        if (list2.head == NULL) return;

        tail->next = list2.head;
        list2.head->prev = tail;
        tail = list2.tail;
    }
};

int main() {
    DoublylinkedList list1, list2;

    list1.insertLast(23);
    list1.insertLast(748);
    list1.insertLast(478);

    list2.insertLast(389);
    list2.insertLast(940);

    cout << "List 1: ";
    list1.printList();

    cout << "List 2: ";
    list2.printList();

    list1.mergeList(list2);
    cout << "Merged List: ";
    list1.printList();

    return 0;
}