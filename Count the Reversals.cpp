int countRev (string s)
{
    if(s.size()%2!=0)
    {
        return -1;
    }
    stack<char>st;
    for(int i=0;i<s.length();i++)
    {
        char ch = s[i];
          
        if(ch == '{')
        {
            st.push(ch);
        }
        else{
         if(!st.empty() && st.top() == '{')
        {
            st.pop();
        }    
        else{
            st.push(ch);        
        }
      }
    }
    int count = 0;
    while(!st.empty())
    {
        char a = st.top(); st.pop();
        char b = st.top(); st.pop();
        if(a == b){
            count+=1;
        }
        else{
            count+=2;
        }
    }
    return count;
}
