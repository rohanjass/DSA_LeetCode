class Solution {
public:
    int find(int x,vector<int>& par){
        if(par[x]!=x) par[x]=find(par[x],par);
    return par[x];
    }
    bool unionFind(int a, int b,vector<int>& par,vector<int>& rank){
        int p1=find(a,par);
        int p2=find(b,par);
        if(p1==p2) return false;
        if(rank[p1]<rank[p2]){
            par[p1]=p2;
            rank[p2]+=rank[p1];
        } else{
            par[p2]=p1;
            rank[p1]+=rank[p2];
        }
    return true;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<int> par(m*n),rank(m*n,1);
        for(int i=0;i<m*n;i++){
            par[i]=i;
        }
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(r+1<m && grid[r+1][c]==grid[r][c]){
                    if(!unionFind(r*n+c,(r+1)*n+c,par,rank)) return true;
                }
                if(c+1<n && grid[r][c+1]==grid[r][c]){
                    if(!unionFind(r*n+c,r*n+c+1,par,rank)) return true;
                }
            }
        }
    return false;
    }
};