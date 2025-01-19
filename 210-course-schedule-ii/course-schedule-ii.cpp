class Solution {
public:
    bool dfs(int crs,unordered_map<int, vector<int>>& prereq,unordered_set<int>& visit,unordered_set<int>& cycle ,vector<int>&output){
        if(visit.count(crs))return true;
        if(cycle.count(crs)) return false;
        cycle.insert(crs);
        if(prereq.count(crs)){
            for(int c:prereq[crs]){
                if(!dfs(c,prereq,visit,cycle,output)) return false;
            }
        }
        visit.insert(crs);
        cycle.erase(crs);
        output.push_back(crs);

    return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> prereq;
        for (const auto& pair : prerequisites) {
            prereq[pair[0]].push_back(pair[1]);
        }
        vector<int> output;
        unordered_set<int> visit;
        unordered_set<int> cycle;

        for(int i=0;i<numCourses;i++){
            if(!dfs(i,prereq,visit,cycle,output))return {};
        }
    return output;
    }
};