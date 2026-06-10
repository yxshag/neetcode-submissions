class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len=numbers.size();
        vector<int> ans;
        int i=0;
        int j=len-1;
        while(true){
            if(numbers[i]+numbers[j]==target){
                ans.push_back(i+1);
                ans.push_back(j+1);
                return ans;
            }
            else if(numbers[i]+numbers[j]<target){i++;
            }
            else{
                j--;
            }
        }

    }
};
