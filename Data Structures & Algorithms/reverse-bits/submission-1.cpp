class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        //this is kind of a recursive approach
        //First reverse every 2 bits, then every 4 bits, then 8, then 16
        //until the whole thing has been reversed.
        n = ((n & 0x55555555) << 1) | ((n & 0xAAAAAAAA) >> 1);
        n = ((n & 0x33333333) << 2) | ((n & 0xCCCCCCCC) >> 2);
        n = ((n & 0x0F0F0F0F) << 4) | ((n & 0xF0F0F0F0) >> 4);
        n = ((n & 0x00FF00FF) << 8) | ((n & 0xFF00FF00) >> 8);
        n = (n << 16) | (n >> 16);
        return n;
    }
};
