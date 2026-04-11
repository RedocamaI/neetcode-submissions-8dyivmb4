class MinStack {
public:
    stack<pair<int, int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        int minel = val;
        if(!st.empty()){
            minel = st.top().second;
        }

        st.push({val, min(minel, val)});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return min(st.top().first, st.top().second);
    }
};
