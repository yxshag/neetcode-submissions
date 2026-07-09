class Solution {
public:
    int sumOfSquaredDigits(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        int slow = n;
        int fast = sumOfSquaredDigits(n);
        //slow and fast pointer helps to identify loops.
        while (fast != 1 && slow != fast) {
            slow = sumOfSquaredDigits(slow);  
            fast = sumOfSquaredDigits(sumOfSquaredDigits(fast)); 
        }
        
        return fast == 1;
    }
};