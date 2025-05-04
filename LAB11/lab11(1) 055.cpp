#include <iostream>
using namespace std;

class queue
{
public:
	int arr[10];
	int front, rear;
	queue()
	{
		front = rear = -1;
	}
	void enqueue(int n)
	{

		if (rear == 9)
		{
			cout << "queue is already full\n";
			return;
		}

		if (front == -1)
		{
			front = 0;
		}
		rear++;
		arr[rear] = n;
	}

	void dequeue()
	{
		if (rear == -1 && front == -1)
		{
			cout << "queue is empty\n";
			return;
		}
		else if (front <= rear)
		{
			front++;
		}
		if (front > rear)
		{
			front = rear = -1;
		}
	}

	void display()
	{
		for (int i = front; i <= rear; i++)
		{
			cout << arr[i];
		}
	}
};
int main()
{

	queue q;
	q.enqueue(3);
	q.enqueue(2);
	q.display();
	q.dequeue();
	q.display();

	return 0;
}