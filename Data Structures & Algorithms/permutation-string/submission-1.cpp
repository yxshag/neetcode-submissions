class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_multiset<char> s1s;
        unordered_multiset<char> s2s;
        int lens1=s1.size(), lens2=s2.size();
        for(auto i:s1)
        {s1s.insert(i);}
        for(int i=0;i<lens2;i++)
        {
            if(i>=lens1){s2s.erase(s2s.find(s2[i-lens1]));}//to remove only 1 of the characters
            s2s.insert(s2[i]);
            if(s1s==s2s){return true;}
        }
        return false;

    }
};
