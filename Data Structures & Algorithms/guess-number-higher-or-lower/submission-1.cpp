/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        bool ans=false;
        int l=1,r=n;
        int mid=0;
        //binary search
        while(l<=r){
            mid=(l+r)/2;
            int val=guess(mid);
            if(val==0){return mid;}
            else if(val==-1){r=mid;}
            else if(val==1){l=mid;}
        }
    }
};