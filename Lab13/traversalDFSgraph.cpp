#include <iostream>
using namespace std;

class Graph {
public:
    int vertices;
    int** adjMatrix;
    bool* visited;

    Graph(int v) {
        vertices = v;
        adjMatrix = new int*[vertices];
        for (int i = 0; i < vertices; i++) {
            adjMatrix[i] = new int[vertices];
            for (int j = 0; j < vertices; j++) {
                adjMatrix[i][j] = 0;
            }
        }
        visited = new bool[vertices];
        for (int i = 0; i < vertices; i++) {
            visited[i] = false;
        }
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    void DFS(int node) {
        visited[node] = true;
        cout << node << " ";

        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[node][i] == 1 && !visited[i]) {
                DFS(i);
            }
        }
    }

    void DFS_Traversal(int start) {
        cout << "traversal of " << start << ": ";
        DFS(start);
        cout << endl;
    }
};

int main() {
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(2, 3);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    g.DFS_Traversal(0);

    return 0;
}