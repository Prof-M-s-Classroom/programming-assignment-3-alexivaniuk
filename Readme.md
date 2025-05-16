[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
Alex Ivaniuk

## Description
Briefly describe what your program does and how the code is structured.

The code uses Prim's algorithm to output the MST, which includes all the edges and their weights

## Files
- graph.h / graph.cpp - Represents the graph by constructing an adjacency matrix and runs Prim's algorithm
- heap.h / heap.cpp - constructs the minHeap and contains important methods like insert() and extractMin()
- main.cpp (unchanged) - calls and runs the code
- README.md

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.

## Time Complexity Analysis


| Operation            | Time Complexity |
|----------------------|-----------------|
| Insert in MinHeap    | O(logn)         |
| Extract Min          | O(1)            |
| Decrease Key         | O(logn)         |
| Prim’s MST Overall   | O(n^2)          |

_Explain why your MST implementation has the above runtime._

Insert as a time complexity O(logn) because in the worst case scenario we need to adjust the array to ensure it still holds the minHeap property, meaning we would have to traverse the height of the heap

Extract Min has a time complexity of O(1) because all of the operations are constant time

Decrease Key also has a time complexity of O(logn) because similarly to insert, in the worst case we need to adjust the array to ensure it still holds the minHeap property

## Test Case Description

Input:  g.addEdge(0, 1, 2);
g.addEdge(0, 3, 6);
g.addEdge(1, 2, 3);
g.addEdge(1, 3, 8);
g.addEdge(1, 4, 5);
g.addEdge(2, 4, 7);
g.addEdge(3, 4, 9);

Output: 0--1 (2)
1--2 (3)
0--3 (6)
1--4 (5)

Challenges Faced: One challenge that I faced was that the weight of the last vertex was printed as INF, which implies it wasn't being reached, and I printed the adjacency matrix to verify that there should be an actual weight. I realized the problem was that I was forgetting to heapify the array when I was inserting and decreasing the key, which ended up solving the issue.