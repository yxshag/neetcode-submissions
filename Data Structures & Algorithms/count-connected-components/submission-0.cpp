class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        //building the adj list
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int ans=0;
        //checking for islands using dfs on every numebr
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans++;
                visited[i]=true;
                dfs(adj, i, visited);
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>>& adj, int child, vector<bool>& visited){
        //just to run standard dfs and mark connected nodes to true
        visited[child]=true;
        for(auto i:adj[child]){
            if(!(visited[i])){
                dfs(adj, i, visited);
            }
        }
    }
};
