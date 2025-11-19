class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int fresh=0;
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) fresh++;
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        int time=0;
        vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        while(fresh && !q.empty()){
            int len=q.size();
            for(int i=0;i<len;i++){
                auto node=q.front();
                q.pop();
                int row=node.first;
                int col=node.second;

                for(auto d:dir){
                    int nr=row+d.first;
                    int nc=col+d.second;

                    if(nr<0 || nc<0 || nr>=m || nc>=n || grid[nr][nc]!=1) continue;
                    fresh--;
                    grid[nr][nc]=2;
                    q.push({nr,nc});
                }
            }
        time++;
        }
    return (fresh==0)? time:-1;
    }
};