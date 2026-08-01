class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int maj=INT_MAX;
        // maintaining a majority variable
        for(auto i:nums){
            if(count==0){
                maj=i;    
            }
            if(i==maj){
                count++;
            }
            else{
                count--;
            }
        }
        return maj;
    }
};