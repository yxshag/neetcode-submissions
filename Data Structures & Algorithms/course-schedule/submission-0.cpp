class Solution {
private:
    bool hasCycle(int node, const vector<vector<int>>& adj, vector<int>& state) {
        //a function that checks for cycles
        state[node] = 1; 
        
        for (int neighbor : adj[node]) {
            if (state[neighbor] == 1) return true; 
            if (state[neighbor] == 0) {           
                if (hasCycle(neighbor, adj, state)) return true;
            }
        }
        
        state[node] = 2; 
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        //creating the adj array
        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }
        //state array
        vector<int> state(numCourses, 0); 
        //checking for loops in directed graph
        for (int i = 0; i < numCourses; ++i) {
            if (state[i] == 0) {
                if (hasCycle(i, adj, state)) return false;
            }
        }
        return true;
    }
};