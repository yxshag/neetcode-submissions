class Solution {
public:
    int countSubstrings(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            //run the loop for every single char and every pair of 2 characters.
            ans+=expand(i, i, s);
            ans+=expand(i, i+1, s);
        }
        return ans;
    }
    //recursive expand function to expand from a particular substring
    int expand(int left, int right, string s){
        //handles out of bounds by returning 0 and if the palindrome still matches, then return 1+expand
        if(left<0||right>=s.size()){
            return 0;
        }
        else if(s[left]==s[right]){
            return 1+expand(left-1,right+1,s);
        }
        else{
            return 0;
        }
    }
};
