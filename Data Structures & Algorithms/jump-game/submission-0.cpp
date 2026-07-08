class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> reach(nums.size(),false);
        reach[0]=true;
        //set starting point as reach
        for(int i=0;i<nums.size();i++){
            if(reach[i]){//if the point is reachable, make all the other points reachable ahead of it till arr[i]
                for(int j=i;j<=i+nums[i];j++){  
                    reach[j]=true;
                }
            }
        }
        return reach[nums.size()-1];
    }
};
