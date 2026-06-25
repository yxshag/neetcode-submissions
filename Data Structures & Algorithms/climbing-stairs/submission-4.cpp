class Solution {
public:
    int climbStairs(int n) {
        //first thing that we directly notice in this question 
        //this is basically fibonacci series
        //because for every value of n we basically have 2 options, we either take the last step as 2 or 1
        //if we take last step as 2 then we have arr[n-2] ways in which we can climb , our last step being 2
        //if we take last step as 1 then we have arr[n-1] ways in which we can climb , our last step being 1
        //so this is a simple dp tabulation solution 

        vector<int> memo(n+1);
        memo[0]=1;
        memo[1]=1;

        if(n>=2){
        memo[2]=2;}
        for(int i=3;i<=n;i++){
            memo[i]=memo[i-1]+memo[i-2];
        }
        return memo[n];
    }
};
