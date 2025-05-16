#ifndef HEAP_H
#define HEAP_H

class MinHeap {
public:
    int* keyArray;
    MinHeap(int capacity) {
        this->capacity = capacity;
        size = 0;
        heapArray = new int[capacity];
        keyArray = new int[capacity];
        position = new int[capacity];

    };
    ~MinHeap() {
        delete[] heapArray;
        delete[] keyArray;
        delete[] position;
    };
    void insert(int vertex, int key) {
        if (size == capacity) {return;}
        int i = size;
        heapArray[i] = vertex;
        keyArray[vertex] = key;
        position[vertex] = size;
        size++;

        minHeapify(0);
    };
    int extractMin() {
        if (size == 0) {return 0;}
        int root = heapArray[0];
        int lastNode = heapArray[size - 1];
        heapArray[0] = lastNode;
        position[lastNode] = 0;
        position[root] = -1;
        size--;
        minHeapify(0);
        return root;
    };
    void decreaseKey(int vertex, int newKey) {
        int i = position[vertex];
        keyArray[vertex] = newKey;

        minHeapify(0);
    };
    bool isInMinHeap(int vertex) {
        return position[vertex] >= 0 && position[vertex] < size;
    };
    bool isEmpty() {
        return size == 0;
    };

private:
    int* heapArray;        // Heap of vertex indices
             // Corresponding key values
    int* position;         // Maps vertex to its position in heap
    int capacity;
    int size;

    void minHeapify(int idx) {
        int smallest = idx;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        if (left < size && keyArray[heapArray[left]] < keyArray[heapArray[smallest]]) {
            smallest = left;
        }
        if (right < size && keyArray[heapArray[right]] < keyArray[heapArray[smallest]]) {
            smallest = right;
        }
        if (smallest != idx) {
            int smallestKey = heapArray[smallest];
            int currentKey = heapArray[idx];
            position[smallestKey] = idx;
            position[currentKey] = smallest;
            std::swap(heapArray[idx], heapArray[smallest]);
            minHeapify(smallest);
        }
    };
};

#endif