class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minval=prices[0];
        int profit=0;
        for(int i=1;i<prices.size();i++)
        {
            minval=min(minval,prices[i]);
            profit=max(profit,prices[i]-minval);
        }
        return profit;
    }
};
