class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>> adj;
        for(auto& t:tickets){
            adj[t[0]].push_back(t[1]);
        }

        for(auto& [from,to]:adj){
            sort(to.rbegin(),to.rend());
        }

        stack<string> st;
        vector<string> res;
        st.push("JFK");
        while(!st.empty()){
            string cur=st.top();
            if(adj[cur].empty()){
                res.push_back(cur);
            st.pop();
            } else {
                string next=adj[cur].back();
                adj[cur].pop_back();
                st.push(next);
            }
        }
    reverse(res.begin(),res.end());
    return res;
    }
};