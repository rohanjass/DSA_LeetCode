class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDeg(numCourses,0);
        queue<int> q;
        for(auto& p:prerequisites){
            adj[p[1]].push_back(p[0]);
            inDeg[p[0]]++;
        }
        for(int i=0;i<numCourses;i++){
            if(inDeg[i]==0) q.push(i);
        }

        int count=0;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int i:adj[node]){
                inDeg[i]--;
                if(inDeg[i]==0){
                    q.push(i);
                }

            }
            count++;
        }
    return count==numCourses;
    }
};