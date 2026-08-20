class Solution {
public:
    // Path compression to find the canonical representative of a node
    int findRoot(vector<int>& parent, int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findRoot(parent, parent[node]);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        
        // Initialize every node as its own parent
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        for (const auto& edge : edges) {
            int root1 = findRoot(parent, edge[0]);
            int root2 = findRoot(parent, edge[1]);

            // If both nodes share the same root, this edge forms a cycle
            if (root1 == root2) {
                return edge;
            }
            
            // Union: attach one root to the other
            parent[root1] = root2;
        }

        return {};
    }
};