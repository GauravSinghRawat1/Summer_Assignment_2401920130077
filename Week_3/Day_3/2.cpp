class MinStack {
private:
    stack<pair<int,int>> st;
    int mn = INT_MAX;
public:
    MinStack() {
    }
    
    void push(int value) {
        st.push({value,mn});
        mn = min(value,mn);
    }
    
    void pop() {
        mn = st.top().second;
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return mn;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */