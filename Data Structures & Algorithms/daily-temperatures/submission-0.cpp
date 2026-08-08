class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        vector<int> ans(temperatures.size(), 0);
        for(int i=0;i<temperatures.size();i++){
            //deleting all the cooler days and updating
            while(!s.empty()&&temperatures[s.top()]<temperatures[i]){
                ans[s.top()]=i-s.top();
                s.pop();
            }
            //pushing teh current element onto the stack
            s.push(i);
            //no need to handle leftover elements as they already have 0;
        }
        return ans;
    }
};
