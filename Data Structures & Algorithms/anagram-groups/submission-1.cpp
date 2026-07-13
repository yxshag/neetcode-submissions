class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        //group the anagrams
        for(auto word:strs){
            string value=word;
            sort(word.begin(),word.end());
            m[word].push_back(value);
        }
        //add the grouped vectors to the result
        vector<vector<string>> result;
        for(auto pairVal:m){
            result.push_back(pairVal.second);
        }
        return result;
    }
};
