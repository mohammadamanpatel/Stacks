class Solution {
public:
    vector<int>prevSmallerElement(vector<int>&height)
    {
    stack<int>s;
    s.push(-1);
    vector<int>ans(height.size());
    for(int i=0;i<height.size();i++)
    {
        int cur = height[i];
        while(s.top()!=-1 and height[s.top()]>=cur)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
    }
    vector<int>nextSmallerElement(vector<int>&height)
    {
    stack<int>s;
    s.push(-1);
    vector<int>ans(height.size());
    for(int i=height.size()-1;i>=0;i--)
    {
        int cur = height[i];
        while(s.top()!=-1 and height[s.top()]>=cur)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>next = nextSmallerElement(heights);
        vector<int>prev = prevSmallerElement(heights);
        int MaxArea = INT_MIN;
        for(int i = 0;i<heights.size();i++)
        {
            if(next[i] == -1)
            {
                next[i] = heights.size();
            }
            int area = (heights[i]*(next[i]-prev[i]-1));
            MaxArea = max(MaxArea,area); 
        }
        return MaxArea;
    }
};
