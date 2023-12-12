#pragma once

#include "graph.h"

#include <limits>

template <typename VertexElement, typename EdgeDistance, int N>
Graph<VertexElement,EdgeDistance,N> findMinSpanningTree(Graph<VertexElement,EdgeDistance,N>& graph) {
    const EdgeDistance INFINITE_DISTANCE = std::numeric_limits<EdgeDistance>::max();
    Graph<VertexElement,EdgeDistance,N> mst;
    for (int i = 0; i < N; i++) {
        mst.insertVertex(i, graph.getElement(i));
    }

    // TODO

    return mst;
}
