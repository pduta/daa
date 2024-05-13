#include <iostream>
#include <climits>
#define MAX 100
using namespace std;
int minKey(int key[], bool mstSet[], int vertices) {
int min = INT_MAX, min_index;
for (int v = 0; v < vertices; v++)
if (mstSet[v] == false && key[v] < min)
min = key[v], min_index = v;
return min_index;
}
void printMST(int parent[], int graph[MAX][MAX], int vertices) {
cout << "Edge \tWeight\n";
for (int i = 1; i < vertices; i++)
cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << "
\n";
}
void primMST(int graph[MAX][MAX], int vertices) {
int parent[MAX];
int key[MAX];
bool mstSet[MAX];
for (int i = 0; i < vertices; i++)
key[i] = INT_MAX, mstSet[i] = false;
key[0] = 0;
parent[0] = -1;
for (int count = 0; count < vertices - 1; count++) {
int u = minKey(key, mstSet, vertices);
mstSet[u] = true;
for (int v = 0; v < vertices; v++)
if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])

parent[v] = u, key[v] = graph[u][v];

}
printMST(parent, graph, vertices);
}
int main() {
int vertices;
int graph[MAX][MAX];
cout << "Enter the number of vertices: ";
cin >> vertices;
cout << "Enter the adjacency matrix of the graph:\n";
for (int i = 0; i < vertices; i++)
for (int j = 0; j < vertices; j++)
cin >> graph[i][j];
primMST(graph, vertices);
return 0;
}
