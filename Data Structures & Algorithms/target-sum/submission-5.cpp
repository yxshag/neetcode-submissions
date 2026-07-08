class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //handling base cases
        if(nums.size()==0){return 0;}
        if (nums.size() == 1) {
            return (target == nums[0] || target == -nums[0]) ? 1 : 0;
        }
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        //we are basically maintaining a large matrix that stores all 0's.
        //whenever we add or subtract a number we end up add the number of ways to get there.
        //create a dp array of (nums.size(),2*sum+1) so that we can store the negative values also
        vector<vector<int>> dp(nums.size()+1,vector<int>(2*sum+1,0));
        dp[0][sum]=1;//setting up for the first number
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<2*sum+1;j++){
                if(dp[i][j]!=0){
                    //this is where we chose to either add or subtract the number.
                    dp[i+1][j+nums[i]]+=dp[i][j];
                    dp[i+1][j-nums[i]]+=dp[i][j];
                    }
            }
        }
        return dp[nums.size()][target+sum];
    }
};
