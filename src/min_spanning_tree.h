#pragma once

#include "graph.h"

#include <array>
#include <limits>

template <typename VertexElement, typename EdgeDistance, int N>
Graph<VertexElement,EdgeDistance,N> findMinSpanningTree(Graph<VertexElement,EdgeDistance,N>& graph) {
    const EdgeDistance INFINITE_DISTANCE = std::numeric_limits<EdgeDistance>::max();
    Graph<VertexElement,EdgeDistance,N> mst;
    for (int i = 0; i < N; i++) {
        mst.insertVertex(i, graph.getElement(i));
    }
    std::array<bool,N> inCloud {};
    inCloud[0] = true;

    while (mst.getNumEdges() < N - 1) {
        int minDistance = INFINITE_DISTANCE;
        std::pair<int,int> minEdge;

        for (int i = 0; i < N; i++) {
            if (inCloud[i]) {
                for (int j = 0; j < N; j++) {
                    if (!inCloud[j] && graph.areAdjacent(i, j) && graph.getDistance(i, j) < minDistance) {
                        minDistance = graph.getDistance(i, j);
                        minEdge = std::make_pair(i, j);
                    }
                }
            }
        }

        mst.insertEdge(minEdge.first, minEdge.second, graph.getDistance(minEdge.first, minEdge.second));
        inCloud[minEdge.second] = true;
    }

    return mst;
}
