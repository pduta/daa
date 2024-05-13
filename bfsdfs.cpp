#include <iostream>
using namespace std;
const int MAX_VERTICES = 100;
class Graph {
int V;
int** adj;
public:
Graph(int V) {
this->V = V;
adj = new int*[V];
for (int i = 0; i < V; ++i) {
adj[i] = new int[V];
for (int j = 0; j < V; ++j)
adj[i][j] = 0;
}
}
void addEdge(int v, int w) {
adj[v][w] = 1;
}
void BFS(int startVertex) {
bool visited[MAX_VERTICES] = {false};
int queue[MAX_VERTICES];
int front = 0, rear = 0;
visited[startVertex] = true;
queue[rear++] = startVertex;
cout << "BFS starting from vertex " << startVertex << ": ";
while (front != rear) {
int current = queue[front++];
cout << current << " ";
for (int i = 0; i < V; ++i) {
if (adj[current][i] && !visited[i]) {
visited[i] = true;
queue[rear++] = i;
}

}
}
cout << endl;
}
void DFSUtil(int v, bool visited[]) {
visited[v] = true;
cout << v << " ";
for (int i = 0; i < V; ++i) {
if (adj[v][i] && !visited[i])
DFSUtil(i, visited);
}
}
void DFS(int startVertex) {
bool visited[MAX_VERTICES] = {false};
cout << "DFS starting from vertex " << startVertex << ": ";
DFSUtil(startVertex, visited);
cout << endl;
}
};
int main() {
int choice, vertices, edges, startVertex, v, w;
cout << "Enter the number of vertices in the graph: ";
cin >> vertices;
Graph g(vertices);
do {
cout << "\nMenu:\n";
cout << "1. Add edge\n";
cout << "2. Breadth-First Search (BFS)\n";
cout << "3. Depth-First Search (DFS)\n";
cout << "4. Exit\n";
cout << "Enter your choice: ";
cin >> choice;
switch (choice) {
case 1:
cout << "Enter vertices (u v) for the edge (Enter -1 -1 to

end): ";

cin >> v >> w;
while (v != -1 && w != -1) {
g.addEdge(v, w);
cout << "Edge added between " << v << " and " << w <<

endl;

cin >> v >> w;
}
break;
case 2:
cout << "Enter the starting vertex for BFS traversal: ";
cin >> startVertex;
g.BFS(startVertex);
break;
case 3:
cout << "Enter the starting vertex for DFS traversal: ";
cin >> startVertex;
g.DFS(startVertex);
break;
case 4:
cout << "Exiting...\n";
break;
default:
cout << "Invalid choice. Please try again.\n";
}
} while (choice != 4);
return 0;
}
