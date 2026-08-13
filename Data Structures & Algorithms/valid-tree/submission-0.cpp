class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1){return false;}
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        //building the adj list
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        //checking for tree using dfs
        visited[0]=true;
        if(dfs(adj, 0, -1, visited)==false){
            return false;
        }
        //checking for disconnected islands
        for(int i=0;i<n;i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
    }

    bool dfs(vector<vector<int>>& adj, int child, int parent, vector<bool>& visited){
        visited[child]=true;
        for(auto i:adj[child]){
            //if i is not the parent and still visited that means there is a loop somewhere
            if(visited[i]&&i!=parent){
                return false;
            }
            //if i is not the parent and not visited, then run the dfs and check
            if(i!=parent&&dfs(adj, i, child, visited)==false){
                return false;
            }

        }
        //if everything passes, that means no anomalies found
        return true;
    }
};
