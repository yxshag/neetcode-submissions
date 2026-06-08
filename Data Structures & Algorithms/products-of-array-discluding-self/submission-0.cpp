class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size=nums.size();
        vector<int> prodLeft(size);
        vector<int> prodRight(size);
        vector<int> ans(size);

        int left=1;
        int right=1;
        for(int i=0;i<size;i++)
        {
            left*=nums[i];
            prodLeft[i]=left;
        }
        for(int i=size-1;i>=0;i--)
        {
            right*=nums[i];
            prodRight[i]=right;
        }
        ans[0]=prodRight[1];
        ans[size-1]=prodLeft[size-2];
        for(int i=1;i<size-1;i++)
        {
            ans[i]=prodLeft[i-1]*prodRight[i+1];
        }
        return ans;
    }
};
