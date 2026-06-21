class Solution {
public:
    vector<vector<int>> res;
    set<vector<int>> s;
    vector<int> subset;
    
    //taking input
    vector<vector<int>> subsetsWithDup(vector<int>& nums_in) {
        vector<int> nums = nums_in;
        sort(nums.begin(),nums.end());
        dfs(0, nums);
        for(auto i:s){res.push_back(i);}
        return res;
    }

    //dfs recursive function that takes index i and sum until i
    void dfs(int start,vector<int>& nums){
        if (start==nums.size()) {//base case
            s.insert(subset);
            return;
        }
        //runs this for every element in the set and skip the duplicate ones
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i-1]) continue; // skip duplicates at this level
            subset.push_back(nums[i]);
            dfs(i + 1, nums);//either select it 
            subset.pop_back();
            dfs(i+1,nums);// or dont select it
        }
    }
};
