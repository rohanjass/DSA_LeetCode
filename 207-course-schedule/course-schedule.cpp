class Solution {
public:
    unordered_map<int,vector<int>> mp;
    unordered_set<int> visiting;

    bool def(int c){
        if(visiting.count(c)) return false;
        if(mp[c].empty()) return true;
        visiting.insert(c);
        for(int i:mp[c]){
            if(!def(i)) return false;
        }
        visiting.erase(c);
        mp[c]={};
    return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i=0;i<numCourses;i++){
            mp[i]={};
        }
        for(auto& p:prerequisites){
            mp[p[0]].push_back(p[1]);
        }
        for(int i=0;i<numCourses;i++){
            if(!def(i)) return false;
        }
    return true;
    }
};