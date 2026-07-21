class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s="(";
        recr(n, 1, 0, s, ans);
        return ans;
    }
    void recr(int n, int open, int close, string s, vector<string>& ans){
        //if string size is 2n , meaning string is complete, so return
        if(s.size()==2*n){
            ans.push_back(s);
            return;
        }
        //option to add open brack
        if(open<n){
            s+='(';
            recr(n, open+1, close, s, ans);
            s.pop_back();
        }
        //option to add close brack
        if(close<open){
            s+=')';
            recr(n, open, close+1, s, ans);
            s.pop_back();
        }
    }
};
