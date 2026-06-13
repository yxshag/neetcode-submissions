class Solution {
public:
    bool matching(char a, char b)
{
    return ((a == '(' && b == ')') ||
            (a == '{' && b == '}') ||
            (a == '[' && b == ']'));
}
    bool isValid(string s) {
    stack<char> st;
    for (char x : s)
    {
        if (x == '(' || x == '{' || x == '[')
            st.push(x);
        else
        {
            if (st.empty() == true)
                return false;
            if (matching(st.top(), x) == false)
                return false;
            else
                st.pop();
        }
    }
    return (st.empty() == true);
    }
};
