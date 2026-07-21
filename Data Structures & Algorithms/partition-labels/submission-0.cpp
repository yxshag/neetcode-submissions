class Solution {
public:
    vector<int> partitionLabels(string s) {
        //creating unordered_map that stores the values of last indexes of each different character
        unordered_map<char, int> m;
        for(int i=s.size()-1;i>=0;i--){
            if(!m[s[i]]){
                cout<<s[i]<<i;
                m[s[i]]=i;
            }
        }
        vector<int> ans;
        int i=-1;
        int currwind=0;
        int j=0;
        //running the loop to check for which strings can be split how
        while(j<s.size()){
            currwind=max(currwind, m[s[j]]);
            if(currwind==j){
                ans.push_back(j-i);
                i=j;
            }
            j++;
        }
        return ans;
    }
};
