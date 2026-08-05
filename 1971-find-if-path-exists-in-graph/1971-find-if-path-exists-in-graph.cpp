#include <vector>
#include <queue>

class Solution {
public:
    /**
     * @brief Determines if there is a valid path from source to destination in a graph.
     * 
     * METHODOLOGY: Breadth-First Search (BFS)
     * 1. Build an adjacency list to represent the graph (the network of roads).
     * 2. Use a queue to explore nodes level by level, starting from the source.
     * 3. Maintain a visited array (clipboard) to prevent getting stuck in loops and redundant work.
     * 4. If we encounter the destination node during traversal, return true.
     * 
     * COMPLEXITY ANALYSIS:
     * - Time Complexity: O(V + E), where V is the number of vertices (nodes) and E is the number of edges.
     * - Space Complexity: O(V + E) to store the graph adjacency list, visited array, and BFS queue.
     */
    bool validPath(int n, std::vector<std::vector<int>>& edges, int source, int destination) {
        // Step 1: Build the Adjacency List (The City Map)
        std::vector<std::vector<int>> graph(n);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u); // Undirected road goes both ways
        }
        
        // Step 2: Initialize the Visited Clipboard and the Queue
        std::vector<bool> visited(n, false);
        std::queue<int> q;
        
        // Start at the source
        q.push(source);
        visited[source] = true;
        
        // Step 3: Drive until no houses are left in the queue
        while (!q.empty()) {
            int currentNode = q.front();
            q.pop();
            
            // If we reached our destination, success!
            if (currentNode == destination) {
                return true;
            }
            
            // Visit all neighboring intersections
            for (int neighbor : graph[currentNode]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        
        // If the queue empties and we never hit the destination
        return false;
    }
};