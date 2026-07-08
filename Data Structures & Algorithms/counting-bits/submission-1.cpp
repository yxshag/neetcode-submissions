class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> memo(n+1);
        memo[0]=0;
        if(n==0){return memo;}
        memo[1]=1;
        for(int i=2;i<=n;i++){
            memo[i]=1+memo[i&(i-1)];
        }
        return memo;
    }
};
