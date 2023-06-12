class Solution {
public:
    bool isValid(string s) {
        if(s[0]!='a')
        {
            return false;
        }
        stack<char>st;
        for(char ch:s)
        {
            if(ch == 'a')
            {
                st.push('a');
            }
            if(ch == 'b')
            {
                if(!st.empty() and st.top() == 'a')
                {
                    st.push('b');
                }
                else{
                    return false;
                }
            }
            if(ch == 'c')
            {
                if(!st.empty() and st.top() == 'b')
                {
                    st.pop();
                if(!st.empty() and st.top() == 'a')
                {
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else{
              return false;
            }
        }
     }
        return st.empty();
    }
};  
