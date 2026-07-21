class Solution {
public:
    vector<string> letterCombinations(string digits) {
        //setting up the hashmap
        unordered_map<int, string> m;
        m[2]="abc";m[3]="def";m[4]="ghi";m[5]="jkl";m[6]="mno";m[7]="pqrs";m[8]="tuv";m[9]="wxyz";   
        vector<string> ans;
        string sol="";
        //running recr
        if(digits.size()>0){
            recr(0, digits, ans, sol, m);
        }
        return ans;
    }
    void recr(int i, string& digits, vector<string>& ans, string& sol, unordered_map<int, string>& m){
        //if it reaches end then add to ans and break out
        if(digits.size()==i){
            ans.push_back(sol);
            return;
        }
        //run recr for every possible char of that number.
        else{
            for(auto j:m[digits[i]-'0']){
                sol+=j;
                recr(i+1, digits, ans, sol, m);
                sol.pop_back();
            }
        }
    }
};
