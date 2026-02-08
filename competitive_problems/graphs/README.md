# CheatSheet

## For Statement Problems
How to decide: BFS vs DFS?
Here is a mental checklist (Decision Matrix) you can use for any grid/graph problem:

Choose BFS (Breadth-First Search) when:
Shortest Path / Minimum Steps: You need the shortest path in an unweighted graph (e.g., "Find the minimum steps to reach the target," "Least number of turns").

Level-by-Level Processing: The problem asks about "layers," "levels," or time steps (e.g., "Rotten Oranges," "Burn the Tree").

Multiple Sources: You have multiple starting points (like multiple rotten oranges) that all act at the same time. BFS can handle this easily by pushing all starting nodes into the Queue at the very beginning.

Choose DFS (Depth-First Search) when:
Exhaustive Search / Backtracking: You need to find all possible solutions or explore every path (e.g., "Find all paths from A to B," "N-Queens," "Sudoku").

Reachability: You just need to know if a path exists, not necessarily the shortest one (e.g., "Can you escape the maze?").

Cycle Detection: Checking if a graph contains a cycle is often easier/more intuitive with DFS.

Connectivity: Counting connected components (like the "Number of Provinces" problem you just solved). Note: BFS works here too, but DFS is often shorter to write.

## For Finding the best Shortest Path

Unweighted Graph: BFS Traversal  

Weighted Graph:  
1. Positive Values [From one source]: Dijistra
2. Both Positive and Negative Values [From one source]: BellMan Ford
3. Both Positive and Negative Values [From all nodes]: Floydd 

