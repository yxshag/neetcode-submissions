class Solution {
public:
    int search(vector<int>& nums, int target) {
    if(nums.size()==1){return nums[0]==target ? 0 : -1;}
    int left = 0, right = nums.size()-1;
    int mid;
    while(left < right) {
        mid = left + (right-left)/2;
        if(nums[mid] > nums[right])
            left = mid+1;
        else
            right = mid;
    }
    right=(left+nums.size());
    while(left<right)
    {
        mid=((left+right)/2);
        if(nums[mid%nums.size()]==target){return mid%nums.size();}
        else if(nums[mid%nums.size()]>target){right=mid;}
        else{left=(mid+1);}

    }
    return -1;

    }
};
