# Graphs Cheat-Sheet  

**Unweighted Graphs -> BFS**
1. Works for **directed and undirected**
2. Works only when all edges have weight = 1
3. BFS guarentees shortest path by layers
4. Store parent[] to reconstruct path  

**Directed Acyclic Graph (DAG) with Weights -> Topological Sort+ Relaxation**  
1. Only works if the graph is DAG
2. Can handle **positive and negative weights** (because no cycle)
3. Steps:
    a. Topological Sort (DFS or Kahn's)
    b. Relax edges in Topological order

**General Weighted Graph  (Directed or undirected, No Negative Weights) -> Dijkstra**  
1. Works for **directed and undirected** graph
2. Works for positive weights
3. Fails for negative edges
4. Find the minimum DISTANCE from the source to every other node  

**Graph with Negative Weights (Directed and Undirected) -> Bellman-Ford**  
1. Works if edges have negative weights
2. Slower than Dijkstra  

**All-pair shortes path (positive or negative weights) -> Floyd-Warshall**  
1. Works with negative edges  

**PRIM's -> Minimum Spanning Tree**  
1. Connect all nodes with minimum TOTAL EDGE COST, but not compute distances. Prim doesn't calculate distance-from-source. Prim simply chooses the cheapest edge that connects the current tree to a new node