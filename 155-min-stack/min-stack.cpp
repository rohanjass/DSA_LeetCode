class MinStack {
    stack<long long> st;
    long long mini=INT_MAX;
public:
    MinStack() { 
    }
    
    void push(int val) {
        long long val2=(long long)val;
        if(st.empty()){
            st.push(val2);
            mini=val2;
        }else{
            if(mini<val2){
                st.push(val2);
            } else{
                st.push(long(2*(val2))-mini);
                mini=val2;
            }
        }
    }
    
    void pop() {
        long long topEle=st.top();
        st.pop();
        if(topEle<mini){
            mini=2*mini-topEle;
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        long long x=st.top();
        if(x<mini) return mini;
        else return x;
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