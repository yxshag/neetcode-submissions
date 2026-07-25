class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        int ans=0;
        for(int i=0;i<operations.size();i++){
            if(operations[i]=="+"){
                int a=s.top();s.pop();
                int b=s.top();s.push(a);
                s.push(a+b);
            }
            else if(operations[i]=="D"){
                s.push(s.top()*2);
            }
            else if(operations[i]=="C"){
                s.pop();
            }
            else{
                //handling values that are more than single digit and negative also
                int val=0;
                int start=0;
                if(operations[i][0]=='-'){
                    start++;
                }
                for(int j=start;j<operations[i].size();j++){
                    val=val*10+(operations[i][j]-'0');
                }
                if(start!=0){
                    val*=-1;
                }
                s.push(val);
            }
        }
        while(!s.empty()){
            ans+=s.top();
            s.pop();
        }
        return ans;
    }
};