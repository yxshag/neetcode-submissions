class Solution {
public:
    bool isAnagram(string s, string t) {
        string p;
        if(s.length()>t.length()){p=t;t=s;s=p;}
        for(auto i:s)
        {
            if(t.find(i)!=-1){
            t.erase(t.find(i),1);}
        }
        if(t=="")
        {return true;}
        return false;
    }
};
