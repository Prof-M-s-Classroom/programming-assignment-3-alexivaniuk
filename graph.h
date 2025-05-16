#ifndef GRAPH_H
#define GRAPH_H
#include "heap.h"

class Graph {
public:
    Graph(int vertices) {
        numVertices = vertices;
        adjMatrix = new int*[numVertices];
        for (int i = 0; i < numVertices; i++) {
            adjMatrix[i] = new int[numVertices];
        }
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {


                adjMatrix[i][j] = INF;

            }
        }
    };
    ~Graph() {
        delete[] adjMatrix;
    };
    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    };
    void primMST() {
        MinHeap* minHeap = new MinHeap(numVertices);
        int* parent = new int[numVertices];
        int* weights = new int[numVertices];
        for (int i = 0; i < numVertices; i++) {
            minHeap->insert(i, INF);
            parent[i] = -1;
            weights[i] = INF;
        }
        weights[0] = 0;
        minHeap->decreaseKey(0, 0);
        while (!minHeap->isEmpty()) {
            int u = minHeap->extractMin();
            for (int i = 0; i < numVertices; i++) {
                int weight = adjMatrix[u][i];

                if (weight != INF && minHeap->isInMinHeap(i) && weight < minHeap->keyArray[i]) {
                    parent[i] = u;
                    weights[i] = weight;
                    minHeap->decreaseKey(i, weight);
                }
            }


        }
        std::cout << "Adjacency Matrix:\n";
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                if (adjMatrix[i][j] == INF)
                    std::cout << "INF ";
                else
                    std::cout << adjMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
        for (int i = 1; i < numVertices; i++) {
            std::cout << parent[i] << "--" << i << " " << "(" << weights[i] << ")" << std::endl;

        }


    };  // Must print MST edges and total weight

private:
    int** adjMatrix;
    int numVertices;
    int INF = INT_MAX;
};

#endif