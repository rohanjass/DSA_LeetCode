class Solution {
    vector<pair<int,int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
public:
    void dfs(int r,int c,vector<vector<bool>>& oc,vector<vector<int>>& arr){
        oc[r][c]=true;
        for(auto& d:dir){
            int nr=r+d.first;
            int nc=c+d.second;
            if(nr>=0 && nc>=0 && nr<arr.size() && nc<arr[0].size() && oc[nr][nc]==false && arr[nr][nc]>=arr[r][c]){
                dfs(nr,nc,oc,arr);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int ROW=heights.size(),COL=heights[0].size();
        vector<vector<bool>>pcf(ROW,vector<bool>(COL,false));
        vector<vector<bool>>atl(ROW,vector<bool>(COL,false));
        for(int r=0;r<ROW;r++){
            dfs(r,0,pcf,heights);//left pcf oc
            dfs(r,COL-1,atl,heights);//right atl oc
        }
        for(int c=0;c<COL;c++){
            dfs(0,c,pcf,heights);//top pcf oc
            dfs(ROW-1,c,atl,heights);//bottom atl oc
        }
        for(int i=0;i<ROW;i++){
            for(int j=0;j<COL;j++){
                if(pcf[i][j] && atl[i][j]){
                    res.push_back({i,j});
                }
            }
        }
    return res;
    }
};