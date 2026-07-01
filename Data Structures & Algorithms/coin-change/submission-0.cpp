class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // create dp array
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        //fill in the dp array with values
        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (i - coin >= 0) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        //handling the case where its not possible to form the amount
        return dp[amount] > amount ? -1 : dp[amount];
    }
};