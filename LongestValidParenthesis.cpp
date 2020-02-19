class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int ans = 0;
        st.push(-1);
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
                st.push(i);
            else
            {
                st.pop();
                if(!st.empty())
                {
                    ans = max(ans,i-st.top());
                }
                else
                {
                    st.push(i);
                }
            }
        }
        return ans;

    }
};
