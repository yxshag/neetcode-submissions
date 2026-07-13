class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlength=0;
        int left=0;
        int right=0;
        unordered_map<char,int> m;
        char recent='\0';
        //sliding window approach
        while(right<s.size()){
            m[s[right]]++;
            // update the duplicate
            if(m[s[right]]>1){
                recent=s[right];
            }
            // shrink the window till the duplicate is removed
            while(m[s[right]]>1){
                m[s[left]]--;
                left++;
            }
            recent='\0';
            //take max length
            maxlength=max(maxlength, right-left+1);
            //extend the window
            right++;
        }
        return maxlength;
    }
};
