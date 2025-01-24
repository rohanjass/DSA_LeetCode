class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        set<pair<int,int>> visit;
        priority_queue<vector<int>,vector<vector<int>>,greater<>>minH;
        vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        minH.push({grid[0][0],0,0});
        visit.insert({0,0});
        while(!minH.empty()){
            auto curr=minH.top();
            minH.pop();
            int t=curr[0],r=curr[1],c=curr[2];
            if(r==n-1 && c==n-1) return t;
            for(const auto& d:dir){
                int row=r+d[0],col=c+d[1];
                if(row<0 || col<0 || row==n || col==n || visit.count({row,col})) continue;
                visit.insert({row,col});
                minH.push({max(t,grid[row][col]),row,col});
            }
        }
    return -1;
    }
};