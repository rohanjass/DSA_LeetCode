class Solution {
    unordered_map<int,vector<int>> mp;
    unordered_set<int>visited;//visiting courses currently
public:
    bool dfs(int crs){
        if(visited.count(crs)) return false;
        if(mp[crs].empty()) return true;
        visited.insert(crs);
        for(int c:mp[crs]){
            if(!dfs(c)) return false;
        }
        visited.erase(crs);
        mp[crs]={};
    return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i=0;i<numCourses;i++){
            mp[i]={};
        }
        for(const auto& p:prerequisites){
            mp[p[0]].push_back(p[1]);
        }
        for(int i=0;i<numCourses;i++){
            if(!dfs(i)) return false;
        }
    return true;
    }
};