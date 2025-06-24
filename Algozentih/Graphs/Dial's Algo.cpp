#include <bits/stdc++.h>
using namespace std;

// Function to find Shortest Path
vector<int> shortestPath(int n, int src, vector<vector<int>> &edges) {
    vector<vector<vector<int>>> adj(n);
    int maxWeight = 0;
    
    // Build adjacency list and find maximum weight
    for (auto e: edges) {
        adj[e[0]].push_back({e[1], e[2]});
        adj[e[1]].push_back({e[0], e[2]});
        maxWeight = max(maxWeight, e[2]);
    }
    
    // Initialize distance array
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    
    // Create buckets for distances
    int maxDist = (n - 1) * maxWeight;
    vector<unordered_set<int>> buckets(maxDist + 1);
    
    // Add source to bucket 0
    buckets[0].insert(src);
    
    // Process buckets in order
    for (int d = 0; d <= maxDist; d++) {
        
        // Process all nodes in current bucket
        while (!buckets[d].empty()) {
            int u = *buckets[d].begin();
            buckets[d].erase(buckets[d].begin());
            
            // Skip if we already found a better path
            if (d > dist[u]) continue;
            
            // Process all adjacent nodes
            for (auto& edge : adj[u]) {
                int v = edge[0];
                int weight = edge[1];
                int newDist = dist[u] + weight;
                
                // If shorter path found
                if (newDist < dist[v]) {
                    
                    // Remove from old bucket if it was there
                    if (dist[v] != INT_MAX) {
                        buckets[dist[v]].erase(v);
                    }
                    
                    // Update distance and add to new bucket
                    dist[v] = newDist;
                    buckets[newDist].insert(v);
                }
            }
        }
    }
    
    return dist;
}
// Time Complexity: O(V + E + W×V), where W is the maximum weight of an edge.
// Space Complexity: O(V + W×V) for storing buckets and adjacency list.
int main() {
    int n = 9;
    int src = 0;
    vector<vector<int>> edges = {
        {0, 1, 4},
        {0, 7, 8},
        {1, 2, 8},
        {1, 7, 11},
        {2, 3, 7},
        {2, 8, 2},
        {3, 4, 9},
        {3, 5, 14},
        {4, 5, 10},
        {5, 6, 2},
        {6, 7, 1},
        {6, 8, 6},
        {7, 8, 7}
    };
    
    vector<int> res = shortestPath(n, src, edges);
    for (auto val : res) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}