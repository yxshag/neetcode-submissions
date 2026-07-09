class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){return 1;}
        //handles positive n values
        else if(n>0){
            double x_copy=x;
            for(int i=1;i<n;i++){
                x=x*x_copy;
            }
        }
        //handles negative n values
        else{
            double x_copy=1/x;
            for(int i=n;i<=0;i++){
                x=x*x_copy;
            }
        }
        return x;
    }
};
