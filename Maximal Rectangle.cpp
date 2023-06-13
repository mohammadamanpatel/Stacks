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
    int maximalRectangle(vector<vector<char>>& matrix) {
      vector<vector<int>>v;
      int n = matrix.size();
      int m = matrix[0].size();
      for(int i = 0;i<n;i++)
      {
          vector<int>t;
          for(int j = 0;j<m;j++)
          {
             t.push_back(matrix[i][j] - '0');
          }
          v.push_back(t);
      }  
      int area = largestRectangleArea(v[0]); // ye ek puri row ko darshata hai means ek vector

      for(int i = 1;i<n;i++)
      {
          for(int j = 0;j<m;j++)
          {
              if(v[i][j] == 0)
              {
                  v[i][j] = 0;
              }
              else{
                  v[i][j] += v[i-1][j];
              }
          }
          area = max(area , largestRectangleArea(v[i]));
      }
      return area;
    }
};
