class Solution {
public:
    bool checkValidString(string s) {
        //maintain 2 stacks, 1 for open bracks and 1 for stars
        stack<int> open;
        stack<int> star;
        for(int i=0;i<s.size();i++){
            if(s[i]=='*'){
                star.push(i);
            }
            else if(s[i]=='('){
                open.push(i);
            }
            else{
                //if its a close brac, then erase top element from open if available,
                //if not then from star, if that is also empty then return false
                if(!open.empty()){
                    open.pop();
                }
                else if(!star.empty()){
                    star.pop();
                }
                else{return false;}
            }
        }
        //from the remaining open and * we need to chcek for every open bracket there is a 
        // star that will act as a closing bracket that is after that open brack.
        if(open.size()>star.size()){return false;}
        while(!open.empty()){
            if(open.top()<star.top()){
                open.pop();
                star.pop();
            }
            else{return false;}
        }
        return true;
    }
};
