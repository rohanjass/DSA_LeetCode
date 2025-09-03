class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(const string& c:tokens){
            if(c=="+"){
                int a=st.top(); st.pop();
                int b=st.top(); st.pop();
                st.push(b+a);
            } else if(c=="-"){
                int a=st.top(); st.pop();
                int b=st.top(); st.pop();
                st.push(b-a);
            } else if(c=="/"){
                int a=st.top(); st.pop();
                int b=st.top(); st.pop();
                st.push(b/a);
            } else if(c=="*"){
                int a=st.top(); st.pop();
                int b=st.top(); st.pop();
                st.push(b*a);
            } else {
                st.push(stoi(c));
            }
        }
    return st.top();
    }
};