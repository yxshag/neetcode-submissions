class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()==0){return s;}
        string max_str=s.substr(0, 1);
        int len=s.size();
        //running a loop for every single index in s, and then expanding outwards if it is a palindrome
        for(int i=0;i<len;i++){
            string curr="";
            string dummy="";
            //even length palindrome
            if(s[i]==s[i+1]){dummy=recr(s,i-1,i+2);}
            //odd length palindrome
            curr=recr(s,i-1,i+1);
            if(dummy.size()>=curr.size()){curr=dummy;}
            if(curr.size()>=max_str.size()){
                max_str=curr;
            }
        }
        return max_str;
    }
    //we only need to check first and last letters as it will only reach till this point if the prev string is palindrome
    bool isPalindrome(string s,int start,int end){
        if(s[start]!=s[end]){
            return false;
        }
        else{return true;}

    }
    //recusively calls isPalindrome by expanding the string in both dirn
    string recr(string s,int start,int end){
        if(start<=-1||end>=s.size()||!isPalindrome(s,start,end)){return s.substr(start+1, (end-start-1));}
        else{return recr(s,start-1,end+1);}
    }
};
