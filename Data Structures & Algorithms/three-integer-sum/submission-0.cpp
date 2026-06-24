class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //sort the list
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size()-1-i;j++){
                if(nums[j]>nums[j+1]){
                    int a=nums[j];
                    nums[j]=nums[j+1];
                    nums[j+1]=a;
                }
                
            }
        }
        vector<vector<int>> ans;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(i!=0){if(nums[i]==nums[i-1]){continue;}}//skip duplicate values of i
            int target=-nums[i];//set target
            int j=i+1;int k=nums.size()-1;//2 pointer approach to find the target
            while(j<k){
                int val=nums[j]+nums[k];
                if(val>target){k--;}
                else if(val==target){
                    //push the result into the answer
                    vector<int> dummy;
                    dummy.push_back(nums[i]);
                    dummy.push_back(nums[j]);
                    dummy.push_back(nums[k]);
                    ans.push_back(dummy);
                    count++;
                    j++;k--;
                    while (j < k && nums[j] == nums[j-1]) j++;   // skip duplicate j values 
                    while (j < k && nums[k] == nums[k+1]) k--;   // skip duplicate k values
                }
                else{j++;}
            }
        }
        return ans;

    }
};
