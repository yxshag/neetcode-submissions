class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left=0,right=nums.size(),mid=0;
        //same as binary search
        while(left<right){
            mid=(left+right)/2;
            if(nums[mid]==target){return mid;}
            else if(nums[mid]>target){right=mid;}
            else{left=mid+1;}

        }
        //if target is greater than the mid, then return mid+1 or else mid
        return target>=nums[mid]?mid+1:mid;
    }
};