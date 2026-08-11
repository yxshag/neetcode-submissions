class Solution {
public:
    int maxScore(string s) {
        int ones=0;
        int ans=0;
        int zeros=0;
        int rones=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                ones++;
            }
        }
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='0'){
                zeros++;
            }
            else if(s[i]=='1'){
                rones++;
            }
            ans=max(ans, zeros+ones-rones);
        }
        return ans;
    }
};