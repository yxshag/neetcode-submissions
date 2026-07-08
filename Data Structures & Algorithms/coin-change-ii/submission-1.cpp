class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //the idea is to loop the coins outside of amount, so that we can avoid the repetitive sets
        vector<int> amounts(amount+1);
        amounts[0]=1;//there is 1 way to make amount 0, which is by choosing no coins
        for(int coin:coins){
            for(int i=coin;i<=amount;i++){
                amounts[i]+=amounts[i-coin];
            }
        }
        return amounts[amount];
    }
};
