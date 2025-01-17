class Solution {
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0},{0, 1}, {0, -1}};
public:
    void dfs(int r,int c,vector<vector<bool>>& ocean,vector<vector<int>>& heights){
        ocean[r][c]=true;
        for(auto [nr,nc]:directions){
           int row=r+nr;
           int col=c+nc;
           if(row>=0 && col>=0 && row<heights.size() && col<heights[0].size() && !ocean[row][col] && heights[row][col]>=heights[r][c]){
                dfs(row,col,ocean,heights);
           }
        }

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>res;
        int ROWS=heights.size();
        int COLS=heights[0].size();
        vector<vector<bool>> pcf(ROWS,vector<bool>(COLS,false));
        vector<vector<bool>> atl(ROWS,vector<bool>(COLS,false));
        for(int c=0;c<COLS;c++){
            dfs(0,c,pcf,heights);//top pcf ocean
            dfs(ROWS-1,c,atl,heights);//bottom atl ocean
        }
        for(int r=0;r<ROWS;r++){
            dfs(r,0,pcf,heights);//LEFT pcf ocean
            dfs(r,COLS-1,atl,heights);//RIGHT atl ocean
        }
        for(int i=0;i<ROWS;i++){
            for(int j=0;j<COLS;j++){
                if(pcf[i][j] && atl[i][j]){
                    res.push_back({i,j});
                }
            }
        }
    return res;
    }
};