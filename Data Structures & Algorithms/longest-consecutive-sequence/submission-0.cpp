class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //make a hashmap of the nums array
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]=1;
        }
        int count_max=0;
        for(int i=0;i<nums.size();i++){
            //if the immedieate predecessor is present in the array then ignore it, as that will never be the start of a longest sequence
            if(m[nums[i]-1]){continue;}
            int count=0;
            int val=nums[i];
            //run the loop and check how far can we go till we dont find the val in the array anymore
            while(true){
                if(m[val]==1){count++;val++;continue;}
                break;
            }
            //find max val
            count_max=max(count, count_max);
        }
        return count_max;
    }
};
