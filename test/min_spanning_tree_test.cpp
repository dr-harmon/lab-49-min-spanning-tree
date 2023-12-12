#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark_all.hpp>

#include "min_spanning_tree.h"

using namespace std;

template <typename VertexElement,  typename EdgeDistance, int N>
EdgeDistance getTotalEdgeDistances(const Graph<VertexElement,EdgeDistance, N>& mst)
{
    EdgeDistance total = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            total += mst.getDistance(i, j);
        }
    }
    return total;
}

TEST_CASE("MST for simple graph")
{
	Graph<char,int,4> graph;
	graph.insertVertex(0, 'a');
	graph.insertVertex(1, 'b');
	graph.insertVertex(2, 'c');
	graph.insertVertex(3, 'd');
	graph.insertEdge(0, 1, 2);
	graph.insertEdge(0, 2, 1);
	graph.insertEdge(1, 3, 1);
	graph.insertEdge(2, 3, 1);
    const Graph<char,int, 4>& mst = findMinSpanningTree(graph);
    REQUIRE(mst.areAdjacent(0, 2));
    REQUIRE(mst.areAdjacent(2, 3));
    REQUIRE(mst.areAdjacent(1, 3));
    REQUIRE_FALSE(mst.areAdjacent(0, 1));
    REQUIRE(getTotalEdgeDistances(mst) == 3);
}

TEST_CASE("MST for graph from slides")
{
	Graph<char,int,6> graph;
	graph.insertVertex(0, 'A');
	graph.insertVertex(1, 'B');
	graph.insertVertex(2, 'C');
	graph.insertVertex(3, 'D');
	graph.insertVertex(4, 'E');
	graph.insertVertex(5, 'F');
	graph.insertEdge(0, 1, 2);
	graph.insertEdge(0, 2, 8);
	graph.insertEdge(0, 4, 7);
	graph.insertEdge(1, 2, 5);
	graph.insertEdge(1, 3, 7);
	graph.insertEdge(2, 3, 9);
	graph.insertEdge(2, 4, 8);
	graph.insertEdge(3, 5, 4);
	graph.insertEdge(4, 5, 3);

    const Graph<char,int, 6>& mst = findMinSpanningTree(graph);
    REQUIRE(mst.areAdjacent(0, 1));
    REQUIRE(mst.areAdjacent(0, 4));
    REQUIRE(mst.areAdjacent(1, 2));
    REQUIRE(mst.areAdjacent(3, 5));
    REQUIRE(mst.areAdjacent(4, 5));
    REQUIRE(getTotalEdgeDistances(mst) == 21);
}
