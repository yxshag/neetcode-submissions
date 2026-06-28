class Solution {
private:
    // same as house robber one
    int robLinear(const vector<int>& nums, int start, int end) {
        int prev2 = 0; // Represents dp[i-2]
        int prev1 = 0; // Represents dp[i-1]
        
        for (int i = start; i <= end; ++i) {
            int current = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = current;
        }
        
        return prev1;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // Base cases
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        //Rob houses 0 to n-2
        int max1 = robLinear(nums, 0, n - 2);
        
        //Rob houses 1 to n-1
        int max2 = robLinear(nums, 1, n - 1);
        
        // Return the maximum profit
        return max(max1, max2);
    }
};