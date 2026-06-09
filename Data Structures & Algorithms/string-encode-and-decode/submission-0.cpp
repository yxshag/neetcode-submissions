class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded="";
        for(auto i:strs){
            encoded+=i;
            encoded+=".";
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int arr_c=0;
        int start=0;
        int end=0;
        for(auto i:s){
            if(i=='.'){
                decoded.push_back(s.substr(start, end-start));
                arr_c++;
                start=end+1;
            }
            end++;
        }
        return decoded;
    }
};
