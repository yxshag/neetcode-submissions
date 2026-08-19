class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // If concatenations differ, no common repeating substring exists
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        
        // The length of the GCD string is gcd(len1, len2)
        int gcdLength = std::gcd(str1.length(), str2.length());
        
        return str1.substr(0, gcdLength);
    }
};