class Solution {
    unordered_map<int,vector<int>>preMap;
    unordered_set<int>visit;

public:
    bool dfs(int crs){
        if(visit.count(crs)) return false;//already visited
        if(preMap[crs].empty()) return true;//course comleted succesfully
        visit.insert(crs);
        for(int c:preMap[crs]){
            if(!dfs(c)) return false;
        }
        visit.erase(crs);
        preMap[crs].clear();
    return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i=0;i<numCourses;i++){
            preMap[i]={};
        }
        for(const auto& p:prerequisites){
            preMap[p[0]].push_back(p[1]);
        }
        for(int c=0;c<numCourses;c++){
            if(!dfs(c)) return false;
        }
    return true;
    }

};