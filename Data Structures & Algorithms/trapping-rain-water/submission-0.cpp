class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left_h;
        vector<int> right_h;
        int len=height.size();
        left_h.push_back(0);
        int left_max=0;
        int right_max=0;
        for(int i=1;i<len;i++){
        left_max=max(left_max,height[i-1]);
        left_h.push_back(left_max);
        }
        right_h.push_back(0);
        for(int i=len-2;i>=0;i--){
        right_max=max(right_max,height[i+1]);
        right_h.push_back(right_max);
        }
        reverse(right_h.begin(),right_h.end());
        int ans=0;
        for(int i=0;i<len;i++)
        {
            if(min(left_h[i],right_h[i])-height[i]>=0){
            ans+=min(left_h[i],right_h[i])-height[i];}
        }
        return ans;
    }
};
