class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> st;
    stack<pair<int, size_t> > minst;
    MinStack() {
        
    }
    
    void push(int x) {
        st.push(x);
        if (minst.empty() || x < minst.top().first) {
            minst.push(make_pair(x, st.size()));
        }
    }
    
    void pop() {
        if (minst.top().second == st.size()) {
            minst.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top().first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
