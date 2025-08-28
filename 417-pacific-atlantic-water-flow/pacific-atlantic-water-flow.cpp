class Solution {
public:
    vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(vector<vector<bool>>& oc,int r,int c,vector<vector<int>>& a){
        oc[r][c]=true;
        for(const auto& d:dir){
            int nr=r+d.first;
            int nc=c+d.second;
            if(nr>=0 && nc>=0 && nr<a.size() && nc<a[0].size() && oc[nr][nc]==false && a[r][c]<=a[nr][nc]){
                dfs(oc,nr,nc,a);
            }
        }
    
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size(),n=heights[0].size();
        vector<vector<bool>>pcf(m,vector<bool>(n,false));
        vector<vector<bool>>atl(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            dfs(pcf,i,0,heights);
            dfs(atl,i,n-1,heights);
        }
        for(int i=0;i<n;i++){
            dfs(pcf,0,i,heights);
            dfs(atl,m-1,i,heights);
        }

        vector<vector<int>> res;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pcf[i][j] && atl[i][j]) res.push_back({i,j});
            }
        }
    return res;
    }
};