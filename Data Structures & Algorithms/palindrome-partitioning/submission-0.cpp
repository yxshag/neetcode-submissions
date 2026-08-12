class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        backtrack(0, s, path, ans);
        return ans;
    }
    //backtracking approach that tries every prefix possible in a given string and goes to next iteration for all the strings that have a palindrome prefix
    void backtrack(int start, string& s, vector<string>& path, vector<vector<string>>& result){
        if(start>=s.size()){
           result.push_back(path);
           return ; 
        }
        for(int i=start;i<s.size(); i++){
            string chck=s.substr(start, i-start+1);
            if(isPalindrome(chck)){
                path.push_back(chck);
                backtrack(i+1, s, path, result);
                path.pop_back();
            }
        }

    }
    //checks palindrome
    bool isPalindrome(string &s){
        for(int i=0;i<=s.size()/2;i++){
            if(!(s[i]==s[s.size()-i-1])){
                return false;
            }
        }
        return true;
    }
};
