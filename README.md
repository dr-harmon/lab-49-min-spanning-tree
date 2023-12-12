# Lab 49: Minimum Spanning Tree

In this lab, we will find the min-spanning tree of a graph using Prim's method.

Achieving the best performance for this method requires a location-aware heap to find the vertex with the minimum distance. However, such a heap does not exist in the STL, so we will use a brute force search of all edges instead. Although this is slower, it is also much simpler to implement.

To further simplify, we will use a graph ADT based on the adjacency matrix. That is, each vertex is referenced by an integer from 0 to n - 1, where n is the number of vertices in the graph. The graph ADT will still use a template for vertex elements and edge distances. For example, a graph of 6 vertices with a string on each vertex and integer edge weights would have the type `Graph<string,int,6>`.

With this ADT as a foundation, fill in the implementation for `findMinSpanningTree` until all unit tests pass. Here is the pseudocode:

    Algorithm BruteForcePrim(G):
        Input: A weighted connected graph G with n vertices and m edges
        Output: A minimum spanning tree T for G
      Create a graph with the same vertices (but no edges) as the original. This is the MST.
      Create a data structure to keep track of which vertices have been added to the "cloud". This can be an array, vector, hash table, or `std::set`.
      Add the first vertex (0) to the cloud.
      Keep track of the minimum distance minDistance seen so far, initialized to some maximum.
      Keep track of the minimum edge seen so far.
      while the number of edges in the MST is less than n - 1 do
        for each vertex i in the graph do
          if the vertex i is in the cloud then
            for each vertex j in the graph do
              if j is not in the cloud and i and j are adjacent and the distance between i and j is less than the minimum then
                Set the distance between i and j as the new minimum distance.
                Set the edge between i and j as the new minimum edge.
        Insert a new edge between i and j into the MST with the same weight as the edge in the original graph.
        Add the destination vertex of the minimum edge to the cloud.
      return the MST
