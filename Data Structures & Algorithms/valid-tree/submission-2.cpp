class Solution {
private:
    bool hasCycle(int node, const vector<vector<int>>& adj, vector<int>& state, vector<int>& order_of_course) {
        //a function that checks for cycles and updates the final vec
        if(state[node]!=2)//only do it if the node hasnt been added yet
        {state[node] = 1;
        
        for (int neighbor : adj[node]) {
            if (state[neighbor] == 1) return true; 
            if (state[neighbor] == 0) {           
                if (hasCycle(neighbor, adj, state, order_of_course)) return true;
            }
        }
        order_of_course.push_back(node);
        state[node] = 2;}
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        //creating the adj array
        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }
        //state array seperate
        vector<int> state(numCourses, 0);
        //order_of_courses array
        vector<int> order_of_course;
        //checking for loops in directed and adding the t graph
        for (int i = 0; i < numCourses; ++i) {
            if (hasCycle(i, adj, state, order_of_course)) return {};
        }
        if(order_of_course.size()==numCourses){
            reverse(order_of_course.begin(),order_of_course.end());
            return order_of_course;
        }
        return {};
    }
};
