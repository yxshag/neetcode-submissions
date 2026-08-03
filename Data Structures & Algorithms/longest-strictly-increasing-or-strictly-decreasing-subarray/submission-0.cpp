class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int lis=1;
        int lds=1;
        int is=1;
        int ds=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                is++;
                ds=1;
                lis=max(lis, is);
                lds=max(lds, ds);
            }
            else if(nums[i]<nums[i-1]){
                ds++;
                is=1;
                lis=max(lis, is);
                lds=max(lds, ds);
            }
            else{
                is=1;
                ds=1;
                lis=max(lis, is);
                lds=max(lds, ds);
            }
        }
        return max(lds, lis);
    }
};