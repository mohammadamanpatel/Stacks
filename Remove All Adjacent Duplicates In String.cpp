class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        string ans = "";
        for(int i = 0;i<s.length();i++)
        {
            char ch = s[i];
            if(!st.empty())
            {
               if(!st.empty() and ch==st.top())
               {
                   st.pop();
               }
               else{
                   st.push(ch);
               }
            }
            else{
                st.push(ch);
            }
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
