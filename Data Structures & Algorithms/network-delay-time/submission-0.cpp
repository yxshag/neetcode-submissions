class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int, int>>> pq;
        vector<vector<pair<int,int>>> adjlist(n);
        vector<int> shortest(n,INT_MAX);
        //making the adjlist
        for(auto i:times){
            adjlist[i[0]-1].push_back(make_pair(i[2],i[1]-1));
        }
        //adding teh source node to pq
        shortest[k-1]=0;
        pq.push(make_pair(0,k-1));
        //now running the djikstra algo
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            //if the node has been explored continue
            if(curr.first<shortest[curr.second]){
                continue;
            }
            //explore all neighbors and add to pq and update shortest distances
            for(auto neighbor_pair:adjlist[curr.second]){
                if(shortest[neighbor_pair.second]>neighbor_pair.first+shortest[curr.second]){
                    shortest[neighbor_pair.second]=neighbor_pair.first+shortest[curr.second];
                    pq.push(make_pair(shortest[neighbor_pair.second],neighbor_pair.second));
                }
            }
        }
        //returning final value
        int maxval=*max_element(shortest.begin(),shortest.end());
        return maxval<INT_MAX?maxval:-1;
    }
};
