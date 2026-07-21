class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> sol;
        //write recr conditions
        recr(nums, target, ans, 0, sol);
        return ans;
    }
    void recr(vector<int>& nums, int target, vector<vector<int>>& ans, int i, vector<int>& sol){
        //target overshoot||out of bounds
        if(target<0||i>=nums.size()){return;}
        //sol found
        else if(target==0){ans.push_back(sol);}
        //run further recr functions
        else{
            sol.push_back(nums[i]);
            recr(nums, target-nums[i], ans, i, sol);
            sol.pop_back();
            recr(nums, target, ans, i+1, sol);
        }
    }
};
