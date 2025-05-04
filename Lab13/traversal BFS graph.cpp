#include <iostream>
using namespace std;

class Queue {
    int* arr;
    int front, rear, size;

public:
    Queue(int capacity) {
        arr = new int[capacity];
        front = rear = -1;
        size = capacity;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int val) {
        if ((rear + 1) % size == front) return;
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        arr[rear] = val;
    }

    int dequeue() {
        if (isEmpty()) return -1;
        int val = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
        return val;
    }

    ~Queue() {
        delete[] arr;
    }
};

class Graph {
    int vertices;
    int** adj;

public:
    Graph(int v) {
        vertices = v;
        adj = new int*[v];
        for (int i = 0; i < v; i++) {
            adj[i] = new int[v];
            for (int j = 0; j < v; j++)
                adj[i][j] = 0;
        }
    }

    void addEdge(int u, int v) {
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    void BFS(int start) {
        bool* visited = new bool[vertices];
        for (int i = 0; i < vertices; i++)
            visited[i] = false;

        Queue q(vertices);
        visited[start] = true;
        q.enqueue(start);

        while (!q.isEmpty()) {
            int current = q.dequeue();
            cout << current << " ";

            for (int i = 0; i < vertices; i++) {
                if (adj[current][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.enqueue(i);
                }
            }
        }

        delete[] visited;
    }

    ~Graph() {
        for (int i = 0; i < vertices; i++)
            delete[] adj[i];
        delete[] adj;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    cout << "BFS Traversal: ";
    g.BFS(0);

    return 0;
}