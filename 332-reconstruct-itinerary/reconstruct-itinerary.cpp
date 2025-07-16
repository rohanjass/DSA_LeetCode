class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>>adj;
        for(const auto& t:tickets){
            adj[t[0]].push_back(t[1]);
        }
        for(auto& [src,dst]:adj){
            sort(dst.rbegin(),dst.rend());
        }
        vector<string> res;
        stack<string> stk;
        stk.push("JFK");
        while(!stk.empty()){
            string curr=stk.top();
            if(adj[curr].empty()){
                res.push_back(curr);
                stk.pop();
            } else{
                string next=adj[curr].back();
                adj[curr].pop_back();
                stk.push(next);
            }
        }
        reverse(res.begin(),res.end());
    return res;
    }
};