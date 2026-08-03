class Solution {
public:
    string minWindow(string s, string t) {
        int formed=0;
        int required=0;
        unordered_map<char, int> ms;
        unordered_map<char, int> mt;
        for(int i=0;i<t.size();i++){
            if(!mt[t[i]]){
                required++;
            }
            mt[t[i]]++;
        }
        int left=0;
        int right=0;
        int shortest=INT_MAX;
        int sleft=-1;
        //Sliding window approach and maintaining a formed, required value approach to check in O(1) time whether or not the substr is valid
        while(right<s.size()){
            ms[s[right]]++;
            if(ms[s[right]]==mt[s[right]]){
                formed++;
            }
            while(formed==required){
                if(right-left+1<shortest){
                    shortest=right-left+1;
                    sleft=left;
                }
                ms[s[left]]--;
                if(ms[s[left]]<mt[s[left]]){
                    formed--;
                }
                left++;
            }
            right++;
        }
        if(sleft>=0){
            return s.substr(sleft, shortest);
        }
        return "";

    }
};
