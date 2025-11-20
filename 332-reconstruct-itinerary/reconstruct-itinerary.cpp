class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>> adj;
        for(auto& t:tickets){
            adj[t[0]].push_back(t[1]);
        }

        for(auto& [src,dst]:adj){
            sort(dst.rbegin(),dst.rend());
        }

        stack<string> st;
        vector<string> res;

        st.push("JFK");

        while(!st.empty()){
            string curr=st.top();
            if(adj[curr].empty()){
                res.push_back(curr);
                st.pop();
            } else {
                string next=adj[curr].back();
                adj[curr].pop_back();
                st.push(next);
            }
        }
        reverse(res.begin(),res.end());
    return res;
    }
};