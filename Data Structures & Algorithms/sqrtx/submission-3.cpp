class Solution {
public:
    int mySqrt(int x) {
        if(x==0||x==1){
            return x;
        }
        int left=1;
        int right=x;
        int mid=x/2;
        int ans=0;//storing the most valid value
        while(left<=right){
            if(mid>x/mid){
                right=mid-1;
            }
            else if(mid<x/mid){
                ans=mid;
                left=mid+1;
            }
            else{
                return mid;
            }
            mid=(left+right)/2;
        }
        return ans;
    }
};