class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1){return 0;}
        int max_index=0;
        int l=0;
        int r=0;
        int count=0;
        //maintain the furthest available index so far and also maintain count everytime you jump
        while(max_index<nums.size()-1){
            for(int i=l;i<=r;i++){
                max_index=max(max_index,i+nums[i]);
            }
            l=r+1;
            r=max_index;
            
            count++;
        }
        return count;
    }
};
