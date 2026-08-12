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
            if(isPalindrome(s, start, i)){
                path.push_back(s.substr(start, i-start+1));
                backtrack(i+1, s, path, result);
                path.pop_back();
            }
        }

    }
    //checks palindrome
    bool isPalindrome(string &s, int start, int end){
        for(int i=start;i<=(start+end)/2;i++){
            if(!(s[i]==s[end+start-i])){
                return false;
            }
        }
        return true;
    }
};
