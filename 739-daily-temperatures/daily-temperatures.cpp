class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>res(temperatures.size(),0);
        stack<pair<int,int>>st;
        for(int i=0;i<temperatures.size();i++){
            int t=temperatures[i];
            while(!st.empty() && t>st.top().first){
                auto top=st.top();
                st.pop();
                res[top.second]=i-top.second;
            }
            st.push({t,i});
        }
    return res;
    }
};