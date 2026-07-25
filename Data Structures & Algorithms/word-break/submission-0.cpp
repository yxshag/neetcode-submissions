class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1,false);
        dp[s.size()]=true;
        //bottom up dp solution
        //keeps checking if the solution is solvable post index i.
        for(int i=s.size()-1;i>=0;i--){
            for(auto j:wordDict){
                string eval=s.substr(i, j.size());
                if(eval==j&&dp[i+j.size()]==true){
                    dp[i]=true;
                }
            }
        }
        return dp[0];
    }
};
