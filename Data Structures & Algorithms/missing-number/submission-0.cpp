class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans=0;
        //xor the ans with all values of i and all values of nums.size()
        //whichever number is missing wont get xor'ed twice, which would 
        //make it remain in teh final ans.
        for(int i=0;i<nums.size();i++){
            ans=ans^i;
            ans=ans^nums[i];
        }
        ans=ans^nums.size();
        return ans;
        }
};
