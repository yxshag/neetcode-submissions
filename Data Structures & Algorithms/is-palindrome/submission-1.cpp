#include <cctype>
class Solution {
public:
    bool isPalindrome(string s) {
        string t;
        for(auto i:s){
            if(isalnum(i)){if(isalpha(i)){t+=tolower(i);}else{t+=i;}}
        }
        int len=t.length();
        for(int i=0;i<len && i<=len-i+2;i++){
            if(t[i]!=t[len-i-1]){
                return false;}
        }
        return true;
    }
};
