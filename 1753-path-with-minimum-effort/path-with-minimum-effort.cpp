class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size(),n=heights[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<>> minH;
        vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        set<pair<int,int>> visited;
        minH.push({0,0,0});

        while(!minH.empty()){
            auto cur=minH.top();
            minH.pop();
            int curDiff=cur[0];
            int r=cur[1];
            int c=cur[2];
            if(r==m-1 && c==n-1) return curDiff;
            if(visited.count({r,c})) continue;
            visited.insert({r,c});
            
            for(auto& d:dir){
                int nr=r+d.first;
                int nc=c+d.second;
                if(nr<0 || nc<0 || nr==m || nc==n || visited.count({nr,nc})) continue;
                int diff=abs(heights[r][c]-heights[nr][nc]);
                minH.push({max(curDiff,diff),nr,nc});
            }
        }
    return -1;
    }
};