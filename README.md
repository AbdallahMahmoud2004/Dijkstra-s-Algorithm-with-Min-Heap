# Dijkstra's Algorithm Implementation

## Project Overview
This project implements Dijkstra's algorithm to find the shortest paths in a weighted graph using a min-heap data structure. It features a `MinHeap` class for priority queue operations and a `WeightedGraph` class for graph representation, showcasing efficient graph traversal and distance calculations. This implementation was developed as an application of graphs and heaps in a Data Structures course.

## Features
- Implementation of Dijkstra's algorithm.
- Min-Heap data structure for efficient priority queue operations.
- Graph representation using an adjacency matrix.
- Input graph data is read from a text file.

## Files
- `MinHeap.h`: Defines the `MinHeap` class for managing heap operations.
- `WeightedGraph.h`: Contains the `WeightedGraph` class for graph representation and Dijkstra's algorithm implementation.
- `main.cpp`: The main program that drives the application.
- `graph.txt`: Input file containing the graph data.

## Usage
1. Compile the code using a C++ compiler:
   ```bash
   g++ main.cpp -o dijkstra
## Example Input
8
15
g a 9
g e 14
g f 15
a b 24
b d 2
b h 19
c b 6
c h 6
d c 11
d h 16
e b 18
e d 30
e f 5
f d 20
f h 44
start g
