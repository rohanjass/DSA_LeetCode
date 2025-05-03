class MinStack {
    int findMiniInStack(stack<int>st,int mini){
        int n=st.size();
        for(int i=0;i<n;i++){
            if(mini>st.top()) mini=st.top();
            st.pop();
        }
    return mini;
    }
public:
    stack<int>st;
    int mini=INT_MAX;
    MinStack() {
    }
    
    void push(int val) {
        if(mini>val) mini=val;
        st.push(val);
    }
    
    void pop() {
        if(st.top()==mini){
            st.pop();
            mini=INT_MAX;
            mini=findMiniInStack(st,mini);
        }
        else st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */