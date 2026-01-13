class Solution {
public:
    vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    void def(vector<vector<bool>>& oc,int r,int c,vector<vector<int>>& a){
        oc[r][c]=true;
        for(auto& d:dir){
            int nr=r+d.first;
            int nc=c+d.second;
            if(nr<0 || nc<0 || nr>=a.size() || nc>=a[0].size() || oc[nr][nc]==true || a[nr][nc]<a[r][c]) continue;

            def(oc,nr,nc,a);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& height) {
        int m=height.size();
        int n=height[0].size();

        vector<vector<bool>> pcf(m,vector<bool>(n,false));
        vector<vector<bool>> atl(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            def(pcf,i,0,height);
            def(atl,i,n-1,height);
        }

        for(int i=0;i<n;i++){
            def(pcf,0,i,height);
            def(atl,m-1,i,height);
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