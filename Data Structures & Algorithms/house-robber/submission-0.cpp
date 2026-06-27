class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0){return 0;//in case we have empty arr
        }
        //handling base cases
        else if(nums.size()==1){return nums[0];}
        else if(nums.size()==2){return max(nums[0],nums[1]);}
        //making an array of max_val which holds max value robbed till i'th house
        vector<int> max_val(nums.size());
        max_val[0]=nums[0];
        max_val[1]=max(nums[0],nums[1]);
        //loop for updating the values for the rest of the houses
        for(int i=2;i<nums.size();i++){
           max_val[i]= max(max_val[i-1], max_val[i-2]+nums[i]);
           cout<<max_val[i];
        }

        return max_val[nums.size()-1];//returning ans
    }
};
