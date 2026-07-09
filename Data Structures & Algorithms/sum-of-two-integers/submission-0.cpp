class Solution {
public:
    int getSum(int a, int b) {
    //Use unsigned int to avoid undefined behavior from signed overflow
    unsigned int ua = a, ub = b;
    
    while (ub != 0) {
        unsigned int carry = ua & ub;   // bits where both are 1 -> carry
        ua = ua ^ ub;                   //do the xor 
        ub = carry << 1;                //shift teh carry to the right position.
    }
    
    return (int)ua;
    }
};
