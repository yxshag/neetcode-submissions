class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //flip the index value to negative for which we are having the value
        //if we encounter a negative value, then it is repeated
        for(int i=0;i<nums.size();i++){
            if(nums[abs(nums[i]) - 1]<0){return abs(nums[i]);}
            nums[abs(nums[i]) - 1] *= -1;
        }
    }
};
