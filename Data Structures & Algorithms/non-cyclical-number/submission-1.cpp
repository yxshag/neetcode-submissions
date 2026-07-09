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
        unordered_set<int> seen;
        //only run this loop as long as n!=1 or values of n does not exist in seen set.
        while (n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n);
            n = sumOfSquaredDigits(n);
        }
        
        return n == 1;
    }
};