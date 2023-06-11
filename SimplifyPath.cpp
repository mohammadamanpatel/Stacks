class Solution {
public:
    void buildAns(string&ans,stack<string>&st)
    {
        if(st.empty())
        {
            return;
        }
        string minPath = st.top();
        st.pop();
        buildAns(ans,st);
         ans += minPath;
    }
    string simplifyPath(string path) {
        int i = 0;
        stack<string>st;
        while(i<path.length())
        {
            int start = i;
            int end = i+1;
            while(end!=path.size() and path[end]!='/')
            {
                end++;
            }
            i = end;
            string minPath = path.substr(start,end-start);
            if(minPath == "/.")
            {
                continue;
            }
            if(minPath == "/")
            {
               continue;
            }
            if(minPath != "/..")
            {
                st.push(minPath);
            }
            else if(!st.empty()){
                st.pop();
            }
        }
        string ans = st.empty() ? "/" : "";
        buildAns(ans,st);
        return ans;
    }
};
