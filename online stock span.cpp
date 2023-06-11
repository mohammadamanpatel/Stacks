class StockSpanner {
public:
    stack<pair<int,int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
       int span = 1;
       while(!st.empty() and st.top().first<=price)
       {
           span = span + st.top().second;
           st.pop();
       } 
       st.push({price,span});
       return span;
    }
};
