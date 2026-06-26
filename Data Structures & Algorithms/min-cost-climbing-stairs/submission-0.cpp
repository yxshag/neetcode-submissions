class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> min_cost(cost.size()+1);
        //initially value of min cost would be 0 to handle cases of 0 oir 1 steps
        min_cost[cost.size()]=0;
        if(cost.size()>0){min_cost[0]=0;}
        if(cost.size()>1){min_cost[1]=0;}
        //now we need to build the 1d table 
        for(int i=2;i<=cost.size();i++){//min cost basically stores the minimum cost it takes to reach that point
            min_cost[i]=min(cost[i-1]+min_cost[i-1],cost[i-2]+min_cost[i-2]);
        }
        return min_cost[cost.size()];
    }
};
