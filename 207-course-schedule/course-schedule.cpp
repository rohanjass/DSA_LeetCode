class Solution {
    unordered_map<int,vector<int>>mp;
    unordered_set<int> visiting;
public:
    bool dfs(int crs){
        if(visiting.count(crs)) return false;
        if(mp[crs].empty()) return true;
        visiting.insert(crs);
        for(int c:mp[crs]){
            if(!dfs(c)) return false;
        }
        visiting.erase(crs);
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