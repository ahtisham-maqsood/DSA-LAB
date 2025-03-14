#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;

	Node(int d)
	{
		data = d;
		next = NULL;
	}
};

class SinglylinkedList
{
public:
	Node *head;

	SinglylinkedList()
	{
		head = NULL;
	}

	void insertLast(int d)
	{
		Node *newNode = new Node(d);
		if (head == NULL)
		{
			head = newNode;
			return;
		}
		Node *temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}

	void printList()
	{
		Node *temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " -> ";
			temp = temp->next;
		}
		cout << "NULL" << endl;
	}

	void mergeList(SinglylinkedList &list2)
	{
		if (head == NULL)
		{
			head = list2.head;
			return;
		}
		Node *temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = list2.head;
	}
};

int main()
{
	SinglylinkedList list1, list2;

	list1.insertLast(28);
	list1.insertLast(27);
	list1.insertLast(6);

	list2.insertLast(26);
	list2.insertLast(25);

	cout << "List 1: ";
	list1.printList();

	cout << "List 2: ";
	list2.printList();

	list1.mergeList(list2);
	cout << "Merged List: ";
	list1.printList();

	return 0;
}