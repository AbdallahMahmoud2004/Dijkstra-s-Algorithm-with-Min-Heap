#include <iostream>
#include <algorithm>
#include <vector>
#include<numeric>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
#include <fstream>
#include "WeightedGraph.h"

using namespace std;

int main() {
    WeightedGraph graph;
    ifstream inf("graph.txt");
    int numVer;
    string startWord;
    inf >> numVer;
    inf.seekg(0);
    graph.loadGraphFromFile(inf);
    inf >> startWord;
    char startVer;
    inf >> startVer;
    Node distances[numVer];
    char *prev = new char[numVer];
    graph.dijkstra(startVer, prev, distances);
    for (int i = 0; i < numVer; i++) {
        if (distances[i].label == startVer)

            cout << "Node -> " << distances[i].label << " Cost -> " << distances[i].cost << " it is the start Vertex "
                 << endl;

        else
            cout << "Node -> " << distances[i].label << " Cost -> " << distances[i].cost << " previous -> " << prev[i]
                 << endl;
    }
}