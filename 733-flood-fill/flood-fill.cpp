class Solution {
public:
    vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(int r,int c,int tar,vector<vector<int>>& image,int color){
        if(r<0 || c<0 || r>=image.size() || c>=image[0].size() || image[r][c]!=tar) return;
        image[r][c]=color;
        for(const auto& d:dir){
            int nr=r+d.first;
            int nc=c+d.second;
            dfs(nr,nc,tar,image,color);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        dfs(sr,sc,image[sr][sc],image,color);
        return image;
    }
};