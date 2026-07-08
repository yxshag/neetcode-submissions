class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        int idx=0;
        while(n!=0){
            //find teh last bit at idx from right
            int val=n&1;
            //as that to the ans, except assume the it as the 31-idx th bit
            ans+=(val<<(31-idx));
            idx++; 
            n=n>>1;           
        }
        return ans;
    }
};
