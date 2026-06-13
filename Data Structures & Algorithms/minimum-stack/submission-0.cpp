class MinStack {
    stack<int> st;
    stack<int> minst;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){st.push(val);minst.push(val);}
        else{
            st.push(val);
            if(val<minst.top()){minst.push(val);}
            else{minst.push(minst.top());}
        }
    }
    
    void pop() {
        st.pop();
        minst.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};
