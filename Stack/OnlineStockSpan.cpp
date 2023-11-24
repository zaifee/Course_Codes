class StockSpanner {
public:
//maintaining a pair of price and span of price
stack<pair<int,int>>st;

    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        while(!st.empty() && st.top().first <= price){
            span += st.top().second;
            st.pop(); //pop bhi karna bhul gaya tha
        }
        st.push({price, span});  //agar koi value choti nhi mili to aaya hoa price or uska span jo 1 hoga wo push kar diya
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
