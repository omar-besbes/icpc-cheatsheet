= Graph

== Shortest Paths
#raw(read("/code/graph/Dijkstra.h"), lang: "cpp")
#raw(read("/code/graph/BellmanFord.h"), lang: "cpp")
#raw(read("/code/graph/FloydWarshall.h"), lang: "cpp")

// == Network flow
// #raw(read("/code/graph/PushRelabel.h"), lang: "cpp")
// #raw(read("/code/graph/MinCostMaxFlow.h"), lang: "cpp")
// #raw(read("/code/graph/EdmondsKarp.h"), lang: "cpp")
// #raw(read("/code/graph/Dinic.h"), lang: "cpp")
// #raw(read("/code/graph/MinCut.h"), lang: "cpp")
// #raw(read("/code/graph/GlobalMinCut.h"), lang: "cpp")
// #raw(read("/code/graph/GomoryHu.h"), lang: "cpp")

== MST
#raw(read("/code/graph/Prim.h"), lang: "cpp")
#raw(read("/code/graph/Kruskal.h"), lang: "cpp")

// == Matching
// #raw(read("/code/graph/hopcroftKarp.h"), lang: "cpp")
// #raw(read("/code/graph/DFSMatching.h"), lang: "cpp")
// #raw(read("/code/graph/MinimumVertexCover.h"), lang: "cpp")
// #raw(read("/code/graph/WeightedMatching.h"), lang: "cpp")
// #raw(read("/code/graph/GeneralMatching.h"), lang: "cpp")

// == DFS algorithms
// #raw(read("/code/graph/SCC.h"), lang: "cpp")
// #raw(read("/code/graph/BiconnectedComponents.h"), lang: "cpp")
// #raw(read("/code/graph/2sat.h"), lang: "cpp")
// #raw(read("/code/graph/EulerWalk.h"), lang: "cpp")

// == Coloring
// #raw(read("/code/graph/EdgeColoring.h"), lang: "cpp")

// == Heuristics
// #raw(read("/code/graph/MaximalCliques.h"), lang: "cpp")
// #raw(read("/code/graph/MaximumClique.h"), lang: "cpp")
// #raw(read("/code/graph/MaximumIndependentSet.h"), lang: "cpp")

== Tree
// #raw(read("/code/graph/CompressTree.h"), lang: "cpp")
// #raw(read("/code/graph/DirectedMST.h"), lang: "cpp")
#raw(read("/code/graph/HLD.h"), lang: "cpp")
#raw(read("/code/graph/LCA.h"), lang: "cpp")
// #raw(read("/code/graph/LinkCutTree.h"), lang: "cpp")
#raw(read("/code/graph/VirtualTree.h"), lang: "cpp")

== Miscellaneous
#raw(read("/code/graph/TopologicalSort.h"), lang: "cpp")

=== Number of Spanning Trees
// I.e. matrix-tree theorem.
// Source: https://en.wikipedia.org/wiki/Kirchhoff%27s_theorem
// Test: stress-tests/graph/matrix-tree.cpp
Create an $N × N$ matrix `mat`, and for each edge $a → b ∈ G$,
do `mat[a][b]--, mat[b][b]++`
(and `mat[b][a]--, mat[a][a]++` if $G$ is undirected).
Remove the $i$th row and column and take the determinant;  
this yields the number of directed spanning trees rooted at $i$  
(if $G$ is undirected, remove any row/column).

=== Erdős–Gallai theorem
// Source: https://en.wikipedia.org/wiki/Erd%C5%91s%E2%80%93Gallai_theorem
// Test: stress-tests/graph/erdos-gallai.cpp
A simple graph with node degrees $d_1 ≥ … ≥ d_n$ exists iff $d_1 + … + d_n$ is even  
and for every $k = 1 … n$:
$$
∑_{i=1}^k d_i ≤ k(k-1) + ∑_{i=k+1}^n min(d_i, k)
$$
