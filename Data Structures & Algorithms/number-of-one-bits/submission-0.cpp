class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n!=0){
            n=n&(n-1);//n&n-1 gets rid of the LSB which is 1
            count++;
        }
        return count;
    }
};
