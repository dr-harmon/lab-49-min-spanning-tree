#pragma once

#include <array>
#include <ostream>
#include <unordered_map>

template <typename VertexElement, typename EdgeDistance, int N>
class Graph {

private:

    std::unordered_map<int,VertexElement> vertexElements;
    std::array<std::array<EdgeDistance, N>, N> G;
    int numEdges;

public:

    Graph() : G({}), numEdges(0) {}

    void insertVertex(int v, const VertexElement& element) {
        vertexElements[v] = element;
    }

    void insertEdge(int v, int w, EdgeDistance distance) {
        G[v][w] = distance;
        G[w][v] = distance;
        numEdges++;
    }

    bool areAdjacent(int v, int w) const {
        return G[v][w] > 0;
    }

    VertexElement getElement(int v) const {
        return vertexElements.at(v);
    }

    EdgeDistance getDistance(int v, int w) const {
        return G[v][w];
    }

    int getNumEdges() const {
        return numEdges;
    }

    friend std::ostream& operator<<(std::ostream& os, const Graph& graph) {
        os << "graph G {\n";

        for (int i = 0; i < N; i++) {
            os << i << " [label=\"" << graph.vertexElements.at(i) << "\"];\n";
        }

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (graph.areAdjacent(i, j)) {
                    os << i << " -- " << j << " [label=\"" << graph.getDistance(i, j) << "\"];\n";
                }
            }
        }

        os << "}\n";

        return os;
    }
};
