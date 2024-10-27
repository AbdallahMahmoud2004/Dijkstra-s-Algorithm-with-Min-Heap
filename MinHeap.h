
#ifndef UNTITLED37_MINHEAP_H
#define UNTITLED37_MINHEAP_H

#include <iostream>

using namespace std;

struct Node {
    char label;
    int cost;

    Node() {}

    Node(char lab, int c) : label(lab), cost(c) {}
};

class MinHeap {
    Node *heap;
    int index;
    int _size;

public:

    MinHeap(int size) {
        heap = new Node[size];
        _size = size;
        index = 0;

    }

    void minheap(int index) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < _size && heap[left].cost < heap[smallest].cost)
            smallest = left;

        if (right < _size && heap[right].cost < heap[smallest].cost)
            smallest = right;

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            minheap(smallest);
        }
    }

    Node extractMin() {
        if (isEmpty())
            return Node(0, INT_MAX);

        Node root = heap[0];
        heap[0] = heap[_size - 1];
        _size--;
        minheap(0);

        return root;
    }

    void insert(Node node) {
        int i = index;
        heap[i] = node;

        while (i != 0 && heap[(i - 1) / 2].cost > heap[i].cost) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
        index++;
    }

    void decreaseKey(char label, int newCost) {
        for (int i = 0; i < _size; ++i) {
            if (heap[i].label == label) {
                heap[i].cost = newCost;
                while (i > 0 && heap[(i - 1) / 2].cost > heap[i].cost) {
                    swap(heap[i], heap[(i - 1) / 2]);
                    i = (i - 1) / 2;
                }
                break;
            }
        }
    }

    void displayHeap() {
        for (int i = 0; i < _size; i++) {
            cout << heap[i].label << "=" << heap[i].cost << endl;
        }
    }

    bool isEmpty() {
        return _size == 0;
    }
};


#endif
