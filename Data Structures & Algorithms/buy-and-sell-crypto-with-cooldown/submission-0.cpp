class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        //make 3 vectors of size n which hold information of what happens if we 
        //buy->buy on that day/own a stock on that day
        //sell->sell on that day
        //cooldown->do nothing on that day
        vector<int> buy(n), sell(n), cooldown(n);
        buy[0] = -prices[0];
        sell[0] = 0;
        cooldown[0] = 0;

        for (int i = 1; i < n; i++) {
            buy[i] = max(buy[i-1], cooldown[i-1] - prices[i]);
            sell[i] = buy[i-1] + prices[i];
            cooldown[i] = max(cooldown[i-1], sell[i-1]);
        }

        return max(sell[n-1], cooldown[n-1]);
    }
};
