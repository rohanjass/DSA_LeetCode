class Solution {
public:
    string removeStars(string s) {
        stack<char > st;
        string res="";
        for(char c:s){
            if(c=='*'){
                if(!st.empty()) st.pop();
            }
            else{
                st.push(c);
            }
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
    return res;
    }
};