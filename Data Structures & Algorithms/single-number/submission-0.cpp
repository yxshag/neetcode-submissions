class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int final_val=0;
        //whenever we do xor , it gets rids of similar elements
        for(int i=0;i<nums.size();i++){
            final_val=final_val^nums[i];
        }
        return final_val;
    }
};
