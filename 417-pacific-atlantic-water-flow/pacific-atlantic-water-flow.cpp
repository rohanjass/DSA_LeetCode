class Solution {
public:
    vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    void func(int r,int c,vector<vector<bool>>& oc,vector<vector<int>>& a){
        oc[r][c]=true;
        for(auto& d:dir){
            int nr=r+d.first;
            int nc=c+d.second;

            if(nr<0 || nc<0 || nr==a.size() || nc==a[0].size() || oc[nr][nc]==true || a[nr][nc]<a[r][c]) continue;

            func(nr,nc,oc,a);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();

        vector<vector<bool>> pcf(m,vector<bool>(n,false));
        vector<vector<bool>> atl(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            func(i,0,pcf,heights);
            func(i,n-1,atl,heights);
        }
        for(int i=0;i<n;i++){
            func(0,i,pcf,heights);
            func(m-1,i,atl,heights);
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