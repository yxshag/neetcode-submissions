class Solution {
public:
    int reverse(int x) {
        int ans=0;

        while(x!=0){
            int last=x%10;
            if((INT_MAX-last)/10<ans || (INT_MIN-last)/10>ans){return 0;}//out of bounds condition
            ans= ans*10+last;//normal reversal
            x=x/10;
        }
        return ans;
    }
};
