#pragma once

#include "graph.h"

#include <limits>

template <typename VertexElement, typename EdgeDistance, int N>
Graph<VertexElement,EdgeDistance,N> findMinSpanningTree(Graph<VertexElement,EdgeDistance,N>& graph) {
    const EdgeDistance INFINITE_DISTANCE = std::numeric_limits<EdgeDistance>::max();
    Graph<VertexElement,EdgeDistance,N> mst(graph);

    // TODO

    return mst;
}
