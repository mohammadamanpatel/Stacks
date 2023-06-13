class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
        for(char ch:s)
        {
            string stringTorepeat = "";
            if(ch == ']')
            {
               while(!st.empty() and !isdigit(st.top()[0]))
               {
                   stringTorepeat+=st.top() == "[" ? "" : st.top();
                   st.pop();
               }
                string times = "";
               while(!st.empty() and isdigit(st.top()[0]))
               {
                   times+=st.top();
                   st.pop();
               } 
               reverse(times.begin(),times.end());
               int repeatedNo = stoi(times);
               string decodedstring = "";
               while(repeatedNo--)
               {
                  decodedstring+=stringTorepeat;
               }
               st.push(decodedstring);
            }
            else
            {
                string temp(1,ch);
                st.push(temp);
            }
        }
        string ans = "";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
