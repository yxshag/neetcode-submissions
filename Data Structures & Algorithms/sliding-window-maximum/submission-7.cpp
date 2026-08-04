class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        //maintaing a dq with the decreasing order of elements
        for(int i=0;i<nums.size();i++){
            //remove all the smaller indexes from the back smaller than the current value of i, because they can never be the largest one
            while(!dq.empty()&&nums[dq.back()]<=nums[i]){
                dq.pop_back();
                if(dq.empty()){break;}
            }
            //add i to the dq
            dq.push_back(i);
            //remove all the elements that are currently out of bounds
            while(dq.front()<=i-k){
                dq.pop_front();
            }
            //add to the answer
            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
