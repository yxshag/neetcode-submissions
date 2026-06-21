class Solution {
public:
    vector<vector<int>> ans;

    void permutation(vector<int>& nums, int curr){
        //base case condition
        if(curr==nums.size()-1){
            ans.push_back(nums);
            return;
        }
        int a=nums[curr];
        for(int i=curr;i<nums.size();i++)
        {
            nums[curr]=nums[i];
            nums[i]=a;
            permutation(nums, curr+1);
            nums[i]=nums[curr];
            nums[curr]=a;
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        permutation(nums,0);
        return ans;
    }
};
