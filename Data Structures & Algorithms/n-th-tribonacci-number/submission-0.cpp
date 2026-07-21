class Solution {
public:
    int tribonacci(int n) {
        //handle base cases first
        if(n==0){return 0;}
        else if(n==1){return 1;}
        else if(n==2){return 1;}
        else{
            int i=0;int j=1;int k=1;int tribonacci=2;
            //handle further cases using O(1) extra space instead of using dp array
            for(int l=4;l<=n;l++){
                i=j;
                j=k;
                k=tribonacci;
                tribonacci=i+j+k;
            }
            return tribonacci;
        }
    }
};