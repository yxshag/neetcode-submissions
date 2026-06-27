class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0){return 0;//in case we have empty arr
        }
        //handling base cases
        else if(nums.size()==1){return nums[0];}
        else if(nums.size()==2){return max(nums[0],nums[1]);}
        //creating 2 storage vars, which store prev val and prev to prev value, since thos are the only ones we need
        int prev_prev=nums[0];
        int prev=max(nums[0],nums[1]);
        int res=prev;
        //loop for updating the values for the rest of the houses
        for(int i=2;i<nums.size();i++){
            res= max(prev, prev_prev+nums[i]);
            prev_prev=prev;
            prev=res;
        }
        return res;//returning ans
    }
};
