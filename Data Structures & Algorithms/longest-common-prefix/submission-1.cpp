class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        //use the first one as reference
        for(int i=0;i<strs[0].size();i++){
            //check for every value
            for(int j=0;j<strs.size();j++){
                if(i>=strs[j].size()||strs[0][i]!=strs[j][i])
                {
                    return ans;
                }
            }
            ans+=strs[0][i];
        }
        return ans;
    }
};