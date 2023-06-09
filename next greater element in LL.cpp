class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>arr;
        while(head)
        {
            arr.push_back(head->val);
            head = head->next;
        }
        vector<int>ans(arr.size());
        stack<int>s;
        for(int i=0;i<arr.size();i++)
        {
            while(!s.empty() and arr[i] > arr[s.top()])
            {
                ans[s.top()] = arr[i];
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};
