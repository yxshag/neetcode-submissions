class Solution {
public:
    int numDecodings(string s) {
        //setting up the dp array and the base cases
        vector<int> dp(s.size()+1);
        dp[s.size()]=1;
        if(s[s.size()-1]=='0'){dp[s.size()-1]=0;}
        else{dp[s.size()-1]=1;}
        //running backwards for loop as we are doing a bottoms-up dp solution
        for(int i=s.size()-2;i>=0;i--){
            //if curr is a 0 then make dp array also 0
            if(s[i]=='0'){
                dp[i]=0;
            }
            //if its not a 0, then we need to add number of ways in the prev index(i+1)
            //and then prevprev(i+2), but we only add prevprev if s[i] and s[i+1] forms 
            //a valid number between 1 and 26.
            else{
                int prev=dp[i+1];
                int prevprev=0;
                int value=s[i]-'0';
                int preValue=s[i+1]-'0';
                if((value==1)||(value==2 && preValue<=6)){prevprev=dp[i+2];}
                else{prevprev=0;}
                dp[i]=prev+prevprev;
            }
        }
        return dp[0];
    }
};
