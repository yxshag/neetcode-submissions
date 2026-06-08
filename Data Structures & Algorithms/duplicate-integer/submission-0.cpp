class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        int sizenums = nums.size();
        for(int i=0;i<sizenums;i++)
        {
            if(s.count(nums[i])!=0)
            {return true;}
            else{
                s.insert(nums[i]);
            }
        }
        return false;
    }
};