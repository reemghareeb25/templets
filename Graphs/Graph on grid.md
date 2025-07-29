
**knight moves:** 
`int dx[] = {-2, -2, -1, -1, 2, 2, 1, 1};`  
`int dy[] = {1, -1, 2, -2, 1, -1, 2, -2};`

4-dimentions:
`int dx[] = {1, -1, 0, 0};`
`int dy[] = {0, 0, 1, -1};`
`char moves[] = {'D', 'U', 'R', 'L'}; `

8-dimentions:
`int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
`int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};`

#### **1. Shortest Path in a Maze (BFS for pathfinding)**
- Example: "Knight Moves" problem.
#### **2. Multi-source BFS (Fire spread, Zombie spread, etc.)**
- Given multiple starting points, find the minimum time for something to spread.
- Push all **starting points into the queue first** before running BFS.
#### **3. Counting Connected Components (Islands, Clusters, etc.)**
- Find the number of distinct **connected areas** in a grid.
- Use **BFS or DFS** to traverse all adjacent cells of a component.
#### **4. Boundary-Filling Problems (Flood Fill, Water Flow, etc.)**
- Used for **simulating fluid spread** (flood fill, water flow from edges).
- BFS ensures all **reachable** cells are processed optimally.
#### **5. Grid with Constraints (Walls, Traps, Weighted Paths)**
- If **walls or traps exist**, carefully check allowed moves.
- If weights are involved, **Dijkstra’s Algorithm** might be required instead of BFS.



