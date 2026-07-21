class Solution {
public:
    //structure to maintain state
    struct state{
        int node;
        int cost_so_far;
        int stops;
        state(int n, int c, int s){
            this->node=n;
            this->cost_so_far=c;
            this->stops=s;
        }
    };
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        //make adjacency list
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back(make_pair(flights[i][1],flights[i][2]));
            cout<<flights[i][1]<<flights[i][2];
        }
        int min_cost=INT_MAX;
        vector<int> min_cost_to_node(n, INT_MAX);
        queue<state> q;
        q.push(state(src, 0,0));
        //bfs
        while (!q.empty()) {
            //if its a dest check if its the shortest path.
            if (q.front().node == dst) {
                min_cost = min(min_cost, q.front().cost_so_far);
            }
            //if not a destn then if we have stops remaining then, find out what the next node would be 
            //also the next cost for each of the pairs on the adjacency list...only if this is the shortest
            //way to reach this node, then process it , else ignore it.
            else if (q.front().stops <= k) {
                for (int i = 0; i < adj[q.front().node].size(); i++) {
                    int next_node = adj[q.front().node][i].first;
                    int next_cost = q.front().cost_so_far + adj[q.front().node][i].second;
                    if (next_cost < min_cost_to_node[next_node]) {
                        min_cost_to_node[next_node] = next_cost;
                        q.push(state(next_node, next_cost, q.front().stops + 1));
                    }
                }
            }
            
            q.pop();
        }
        return min_cost!=INT_MAX?min_cost:-1;
    }
};
