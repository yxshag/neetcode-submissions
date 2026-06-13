class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto i:tokens)
        {
            if(i != "+" && i != "-" && i != "*" && i != "/"){s.push(stoi(i));}
            else{
            int a=s.top();s.pop();
            int b=s.top();s.pop();
            if(i=="+"){s.push(a+b);}
            else if(i=="-"){s.push(b-a);}
            else if(i=="*"){s.push(a*b);}
            else if(i=="/"){s.push(b/a);}}
        }
        return s.top();
    }
};
