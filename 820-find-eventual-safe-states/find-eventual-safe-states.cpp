class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> revAdj(n);
        vector<int> outDeg(n,0);

        for(int i=0;i<n;i++){
            outDeg[i]=graph[i].size();
            for(int j:graph[i]){
                revAdj[j].push_back(i);
            }
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(outDeg[i]==0) q.push(i);
        }

        vector<int> safe;
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            safe.push_back(node);
            for(int next:revAdj[node]){
                outDeg[next]--;
                if(outDeg[next]==0) q.push(next);
            }
        }

        sort(safe.begin(),safe.end());
        return safe;
    }
};