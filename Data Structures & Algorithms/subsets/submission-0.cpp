class Solution {
public:
    vector<vector<int>> result;
    vector<int> subset;
    vector<int> nums;
    //defining the function for dfs, which is basically running recursively for every single number
    void dfs(int i) {
        //base case condition of recursion
        if (i == (int)nums.size()) {
            result.push_back(subset);
            return;
        }
        // include nums[i]
        subset.push_back(nums[i]);
        dfs(i + 1);
        subset.pop_back();

        // exclude nums[i]
        dfs(i + 1);
    }
    //taking input
    vector<vector<int>> subsets(vector<int>& nums_in) {
        nums = nums_in;
        dfs(0);
        return result;
    }
};
