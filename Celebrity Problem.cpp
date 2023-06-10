class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>s;
        for(int i = 0;i<n;i++)
        {
            s.push(i);
        }
        while(s.size()!=1)
        {
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();
            if(M[a][b])
            {
                s.push(b);
            }
            else{
                s.push(a);
            }
        }
        int isCelebraty = s.top();
        for(int i = 0;i<n;i++)
        {
            if(M[isCelebraty][i]!=0)
            {
                return -1;
            }
        }
        for(int i= 0 ;i<n;i++)
        {
            if(M[i][isCelebraty] == 0 and i!=isCelebraty)
            {
                return -1;
            }
        }
        return isCelebraty;
    }
};
