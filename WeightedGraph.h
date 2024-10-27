
#ifndef UNTITLED37_WEIGHTEDGRAPH_H
#define UNTITLED37_WEIGHTEDGRAPH_H

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include "MinHeap.h"

using namespace std;

class WeightedGraph {
    int **g;
    int nVertices;
    unordered_map<char, int> mp;
    unordered_map<int, char> mpIn;
public:
    int getNVertices() {
        return nVertices;
    }

    int getWeight(char v1, char v2) {
        return g[mp[v1]][mp[v2]];
    }

    int *returnNeighbors(int v) {
        vector<int> vec;
        for (int i = 0; i < nVertices; i++) {

            if (g[v][i] != 0) {
                vec.push_back(i);

            }
        }
        int *arr = new int[vec.size()];
        for (int i = 0; i < vec.size(); i++) {
            arr[i] = vec[i];
        }
        return arr;
    }

    int numNeighbors(int v) {
        int counter = 0;
        for (int i = 0; i < nVertices; i++) {
            if (g[v][i] != 0)
                counter++;
        }
        return counter;
    }

    void loadGraphFromFile(ifstream &infile) {
        string num;
        infile >> num;

        nVertices = stoi(num);
        g = new int *[nVertices];
        for (int i = 0; i < nVertices; i++) {
            g[i] = new int[nVertices];
        }
        for (int i = 0; i < nVertices; ++i) {
            for (int j = 0; j < nVertices; ++j) {
                g[i][j] = 0;
            }
        }
        infile >> num;
        int edges = stoi(num);
        int index = 0;
        while (edges--) {
            char v1, v2;
            string weight;
            infile >> v1 >> v2 >> weight;
            if (!mp.count(v1)) {
                mp[v1] = index;
                mpIn[index] = v1;
                index++;
            }
            if (!mp.count(v2)) {
                mp[v2] = index;
                mpIn[index] = v2;
                index++;
            }
            g[mp[v1]][mp[v2]] = stoi(weight);
        }
    }

    void print() {
        for (int i = 0; i < nVertices; ++i) {
            for (int j = 0; j < nVertices; ++j) {
                if (g[i][j]) {
                    cout << mpIn[i] << " -> ";
                    cout << mpIn[j] << " = ";
                    cout << g[i][j] << endl;
                }
            }
        }
    }

    void dijkstra(char startVertex, char *prev, Node distances[]) {
        MinHeap Heap(nVertices);
        map<char, bool> Visited;
        for (int i = 0; i < nVertices; i++) {
            Visited[mpIn[i]] = false;
        }

        for (int i = 0; i < nVertices; i++) {
            if (mpIn[i] == startVertex) {
                distances[i].label = startVertex;
                distances[i].cost = 0;
            } else {
                distances[i].label = mpIn[i];
                distances[i].cost = INT_MAX;
            }
            Heap.insert(distances[i]);
        }
        while (!Heap.isEmpty()) {
            Node MinNode = Heap.extractMin();
            Visited[MinNode.label] = true;
            int *neighbors = returnNeighbors(mp[MinNode.label]);
            for (int i = 0; i < numNeighbors(mp[MinNode.label]); i++) {

                if (!Visited[mpIn[neighbors[i]]]) {

                    int update = MinNode.cost + getWeight(MinNode.label, mpIn[neighbors[i]]);
                    if (update < distances[neighbors[i]].cost) {
                        distances[neighbors[i]].cost = update;
                        prev[neighbors[i]] = MinNode.label;
                        Heap.decreaseKey(mpIn[neighbors[i]], update);

                    }
                }

            }
        }
    }
};

#endif
