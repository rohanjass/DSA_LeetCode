class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) q.push({i,j});
            }
        }

        if(q.empty() || q.size()==n*n) return -1;
        vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        int res=-1;
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();

            for(auto& d:dir){
                int nr=r+d.first;
                int nc=c+d.second;
                if(nr<0 || nc<0 || nr==n || nc==n || grid[nr][nc]!=0) continue;
                grid[nr][nc]=grid[r][c]+1;
                res=max(res,grid[nr][nc]-1);
                q.push({nr,nc});
            }
        }
    return res;
    }
};