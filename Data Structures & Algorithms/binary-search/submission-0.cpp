class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=-1,right=nums.size(),mid=0;
        while(left<right-1){
            mid=(left+right)/2;
            if(nums[mid]==target){return mid;}
            else if(nums[mid]>target){right=mid;}
            else{left=mid;}

        }
        return -1;
    }
};
