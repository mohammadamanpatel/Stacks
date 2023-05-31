class Solution {
public:
    bool isValid(string st) {
        stack<char>s;
        for(int i=0;i<st.length();i++)
        {
            char ch = st[i];
            if(ch == '(' || ch == '[' || ch == '{')
            {
                s.push(ch);
            } 
            else if(ch == ')' || ch == ']' || ch == '}')
            {
                if(!s.empty())
                {
                    char topofStack = s.top();
                    if((ch == ')'  and  topofStack == '(' ) ||(ch == ']'  and topofStack == '[') || (ch == '}'  and topofStack == '{'))
                    {
                        s.pop();
                    }
                    else{
                        return false;
                    }
                }   
                else{
                    return false; //invalid string empty string di hui hai
                } 
            }
        }
        if(s.empty())
        {
            return true;
        }
        return false;
    }
};
